# movie_publisher
ROS1 package that publish of movie file and webcam

## Dependent

- ROS1 Melodic or Noetic
- OpenCV3.2 or higher

## Installation

- Place the folder in "ROS1 workspace / src".
- cd .. && catkin_make

## Usage

#### webcam_publisher

- `$ rosrun movie_publisher webcam_pub _camera_name:=0 `
- 0 is camera port ("/dev/video0")

#### movie_publisher

- `$ rosrun movie_publisher movie_pub _video_name:=<path to movie file>`

#### picture_publisher

- `$ rosrun movie_publisher picture_pub <path to picture file>`

## Licence

- https://github.com/Ar-Ray-code/movie_publisher/blob/main/LICENSE
