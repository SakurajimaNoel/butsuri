cmake_minimum_required(VERSION 3.19)
project(butsuri)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${butsuri_SOURCE_DIR}/cmake")

add_executable(butsuri src/main.cpp src/window.cpp src/window.h)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})