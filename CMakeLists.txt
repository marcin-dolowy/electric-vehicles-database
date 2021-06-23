cmake_minimum_required(VERSION 3.19)
project(electric_vehicle_database)

set(CMAKE_CXX_STANDARD 14)

add_executable(electric_vehicle_database main.cpp Vehicle.cpp Vehicle.h Car.cpp Car.h)