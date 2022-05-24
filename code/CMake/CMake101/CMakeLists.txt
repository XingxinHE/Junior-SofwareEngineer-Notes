#specify the minimum CMake version
cmake_minimum_required(VERSION 3.10)

#get the directory name as the project name, stored in the variable ProjectId
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
#    this REPLACE means replacing the space to "_" in case the project including white space
string(REPLACE " " "_" ProjectId ${ProjectId})

#set the project
project(${ProjectId})

# add the executable, cmake will automatically find the header files
add_executable(${ProjectId} main.cpp)