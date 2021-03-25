#include <rclcpp/rclcpp.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
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
		// std::shared_ptr<sensor_msgs::msg::Image> image_pub;

		std::string name;


		movie_pub(const std::string &name_space, rclcpp::NodeOptions options):rclcpp::Node(name_space, options)
		{

			name = "/home/ubuntu/Desktop/video.mp4";

			cv::Mat image;
			cv::VideoCapture camera(name.c_str());
			
			float flame_rate = camera.get(cv::CAP_PROP_FPS);

			if (!camera.isOpened()) {
				std::cout << name << " failed to open camera." << std::endl;
			}
			rclcpp::Rate looprate (flame_rate); // capture image at 10Hz
			std::cout << flame_rate << std::endl;

			image_pub = this->create_publisher<sensor_msgs::msg::Image>("image_raw",1);
	
			while(rclcpp::ok())
			{
				camera >> image;
				cv::resize(image, image,cv::Size(416, 234));
				
				header.stamp = system_clock.now();
				header.frame_id = "/map";

				msg = cv_bridge::CvImage(header, "bgr8", image).toImageMsg();
				image_pub->publish(*msg);
				looprate.sleep();
			}
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