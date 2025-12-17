cmake_minimum_required(VERSION 4.0)
project(rocket_sensor_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(rocket_sensor_project main.cpp
        rocket.h)
