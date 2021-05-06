cmake_minimum_required(VERSION 3.19)
project(butsuri)

set(CMAKE_CXX_STANDARD 20)
set(GLFW_H /usr/local/Cellar/glfw/3.3.4/include)
include_directories(${GLFW_H})

set(GLFW_LINK /usr/local/Cellar/glfw/3.3.4/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLFW_LINK})

add_executable(butsuri src/main.cpp src/window.cpp src/window.h src/glad.c)

if (APPLE)
    target_link_libraries(butsuri "-framework OpenGL")
    target_link_libraries(butsuri "-framework GLUT")
endif()
