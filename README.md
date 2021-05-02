# movie_publisher
ROS1 package that publish of movie file and webcam

## Dependent



## Installation

- Place the folder in "ROS1 workspace / src".
- cd .. && catkin_make

## Usage

#### webcam_publisher

- `$ rosrun movie_publisher webcam_pub _camera_name:=0 `
- 0 is camera port ("/dev/video0")

#### movie_publisher

- `$ rosrun movie_publisher movie_pub _video_name:=<path to movie file>`

## Licence


