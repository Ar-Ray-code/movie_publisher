# movie_publisher
ROS2 package that publish of movie file and webcam

## Dependent

- ROS2 Foxy
- OpenCV4 (3 is OK)

## Installation

```bash
cd ~/
mkdir -p ros2_ws/src
cd ros2_ws/src
git clone https://github.com/Ar-Ray-code/movie_publisher -b foxy
cd ~/ros2_ws
colcon build --symlink-install
```

## Usage

#### webcam_publisher

- `$ ros2 run movie_publisher webcam_pub`
- device is `/dev/video2`
  - `$ ros2 run movie_publisher webcam_pub --ros-args -p camera_num:=2`
- w : 1920 h : 1080
  - `$ ros2 run movie_publisher webcam_pub --ros-args -p width:=1920 -p height:=1080`

#### movie_publisher (Not recommended)

- `$ rosrun movie_publisher movie_pub --ros-args -p video_name:=<path to movie file>`

## Licence

- Apache License 2.0 : https://github.com/Ar-Ray-code/movie_publisher/blob/main/LICENSE
