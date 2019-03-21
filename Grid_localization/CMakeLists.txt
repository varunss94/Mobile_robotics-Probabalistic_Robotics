cmake_minimum_required(VERSION 2.8.3)
project(uml_hmm)

#option(BUILD_TEST "Test CXX helper functions" ON)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(query_cxx nodes/helper_functions.hpp
                             nodes/helper_functions.cpp
                             nodes/query_cxx.cpp)
target_link_libraries(query_cxx ${catkin_LIBRARIES})
    
#add_executable(query_display_cxx nodes/helper_functions.hpp
#                             nodes/helper_functions.cpp)
#target_link_libraries(query_cxx ${catkin_LIBRARIES})

add_executable(localizer nodes/helper_functions.cpp
                             nodes/robot_class.cpp
                             nodes/localizer.cpp)
target_link_libraries(localizer ${catkin_LIBRARIES})

