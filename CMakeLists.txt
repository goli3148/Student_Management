cmake_minimum_required(VERSION 3.10)
project(StudentManagement VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(StudentManagement
src/main.cpp
src/student.cpp
src/manager.cpp
)