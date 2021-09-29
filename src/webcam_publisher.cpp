#include <rclcpp/rclcpp.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

rclcpp::Clock system_clock(RCL_ROS_TIME);

class movie_pub : public rclcpp::Node
{
	public:
		std::shared_ptr<rclcpp::Node> param_get_node;
		rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub;
		sensor_msgs::msg::Image::SharedPtr msg;
		std_msgs::msg::Header header;

		rclcpp::TimerBase::SharedPtr timer;

		int camera_num;
		int width;
		int height;
		cv::Mat image;

		cv::VideoCapture camera;

		movie_pub(const std::string &name_space, rclcpp::NodeOptions options):rclcpp::Node(name_space, options)
		{
			// declare parameter
			this->declare_parameter("camera_num", 0);
			this->declare_parameter("width", 640);
			this->declare_parameter("height", 480);

			// get parameter
			camera_num = this->get_parameter("camera_num").as_int();
			width = this->get_parameter("width").as_int();
			height = this->get_parameter("height").as_int();
	
			// cv::VideoCapture camera(camera_num);
			camera.open(camera_num);
			
			float flame_rate = camera.get(cv::CAP_PROP_FPS);

			if (!camera.isOpened()) {
				std::cout << camera_num << " failed to open camera." << std::endl;
			}
			// rclcpp::Rate looprate (flame_rate);
			std::cout << flame_rate << std::endl;

			image_pub = this->create_publisher<sensor_msgs::msg::Image>("image_raw",10);

			std::chrono::nanoseconds duraction(int(1/float(flame_rate)*1000000000));

            timer = this->create_wall_timer(duraction, std::bind(&movie_pub::pub_movie, this));
		}

		void pub_movie()
		{
			camera >> image;
			cv::resize(image, image,cv::Size(width,height));
				
			header.stamp = system_clock.now();
			header.frame_id = "/map";

			msg = cv_bridge::CvImage(header, "bgr8", image).toImageMsg();
			image_pub->publish(*msg);
		}
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
	rclcpp::NodeOptions options;
	auto node = std::make_shared<movie_pub>("movie_pub", options);
	
	rclcpp::spin(node);
	rclcpp::shutdown();
	return 0;
}