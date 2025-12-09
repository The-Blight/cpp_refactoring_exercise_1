cmake_minimum_required(VERSION 4.0.2)
project(university)

set(CMAKE_CXX_STANDARD 20)

add_executable(University main.cpp
        include/Exceptions.h
        include/Date.h
        include/Teacher.h)

target_include_directories(University PUBLIC ${PROJECT_SOURCE_DIR} ./include)

