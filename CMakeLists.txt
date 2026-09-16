cmake_minimum_required(VERSION 4.4.3)

project(corruptor VERSION 0.1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp)

set_property(TARGET corruptor PROPERTY CXX_STANDARD 23)