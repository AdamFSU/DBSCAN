cmake_minimum_required(VERSION 3.17)
project(DBSCAN)

set(CMAKE_CXX_STANDARD 14)

add_executable(DBSCAN main.cpp dbscan.cpp dbscan.h point.cpp point.h)