# movie_publisher
ROS1 package that publish of movie file and webcam

## Dependent

- ROS1 Melodic
- OpenCV3.2

## Installation

- Place the folder in "ROS1 workspace / src".
- cd .. && catkin_make

## Usage

#### webcam_publisher

- `$ rosrun movie_publisher webcam_pub 0 `
- 0 is camera port ("/dev/video0")

#### movie_publisher

- `$ rosrun movie_publisher movie_pub <path to movie file>`

## Licence

- MIT : https://github.com/Ar-Ray-code/movie_publisher/blob/main/LICENSE