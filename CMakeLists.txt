cmake_minimum_required(VERSION 3.1)
# ①改工程名字
project(test)

set( CMAKE_CXX_FLAGS "-std=c++14 -O3" )

# ②添加库文件
# ROS
find_package(catkin REQUIRED COMPONENTS
		roscpp
		rospy
		std_msgs
		sensor_msgs
		)

# OpenCV
SET(OpenCV_DIR "/media/hongfeng/Storage/Code/ADynaSLAM/Thirdparty/opencv-4.5.1/build")
message("PROJECT_SOURCE_DIR: " ${OpenCV_DIR})
find_package(OpenCV 4.5.1 REQUIRED)
MESSAGE(STATUS "OpenCV version: "${OpenCV_VERSION})

# Pangolin
find_package(Pangolin REQUIRED)

# Ceres
find_package(Ceres REQUIRED)
message("ceres: " ${Ceres_INCLUDE_DIRS})

# Python
SET(Python3_ROOT_DIR "/media/hongfeng/Storage/Ubuntu/anaconda3/bin")
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# G2O\EIGEN
include_directories(${OpenCV_DIRS}
		${Pangolin_INCLUDE_DIRS}
		${Ceres_INCLUDE_DIRS}
		${Python3_INCLUDE_DIRS}
		"/usr/local/include/g2o"
		"/usr/include/eigen3")

# ☂生成可执行文件
add_executable( Pythontest Cpython/test_python.cpp)

# ④添加软连接
target_link_libraries(Pythontest 
${OpenCV_LIBS} 
g2o_core g2o_stuff 
pangolin 
${CERES_LIBRARIES} 
${Python3_LIBRARIES})
