cmake_minimum_required(VERSION 3.31)
project(Experiments)

set(CMAKE_CXX_STANDARD 23)

add_executable(Experiments main.cpp
        src/experiment01/ex01.cpp
        include/LifeTime.h
        include/TypeName.h)
target_include_directories(Experiments PUBLIC include)
