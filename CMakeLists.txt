cmake_minimum_required(VERSION 3.19)
project(butsuri)

set(CMAKE_CXX_STANDARD 20)
set(GLFW_H "C:\\Program Files (x86)\\glfw-3.0.4\\include")
set(GLFW_LINK "C:\\Program Files (x86)\\glfw-3.0.4\\lib\\glfw3.lib")

set(FASTNOISE_H "C:\\Program Files (x86)\\FastNoise2\\include")
set(FASTNOISE_LIB "C:\\Program Files (x86)\\FastNoise2\\lib\\FastNoise.lib")

if (APPLE)
    set(GLFW_H /usr/local/Cellar/glfw/3.3.4/include)
    set(GLFW_LINK /usr/local/Cellar/glfw/3.3.4/lib/libglfw.3.dylib)
endif()

include_directories(${GLFW_H} ${FASTNOISE_H})

link_libraries(${OPENGL} ${GLFW_LINK} ${FASTNOISE_LIB})


add_executable(butsuri src/main.cpp src/window.cpp include/window.h src/glad.c src/baseDrawable.cpp include/baseDrawable.h src/triangle.cpp include/triangle.h src/cube.cpp include/cube.h src/camera.cpp include/camera.h include/time.h src/time.cpp src/skybox.cpp include/skybox.h src/chunk.cpp include/chunk.h include/chunkManager.h src/chunkManager.cpp)

if (APPLE)
    target_link_libraries(butsuri "-framework OpenGL")
    target_link_libraries(butsuri "-framework GLUT")
endif()
