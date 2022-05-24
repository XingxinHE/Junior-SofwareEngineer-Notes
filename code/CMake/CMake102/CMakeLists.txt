#specify the minimum CMake version
cmake_minimum_required(VERSION 3.10)

#set the project
project(cmake102)

#add library
add_library(math_lib math.cpp)

# add the executable, cmake will automatically find the header files
add_executable(cmake102 main.cpp)

target_link_libraries(cmake102 PUBLIC math_lib)