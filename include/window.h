#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
private:
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    GLFWwindow *pWindow;
public:
    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    GLFWwindow *getWindow();

    Window(int width, int height);

    ~Window();

    Window(const Window &) = delete;

    Window &operator=(const Window &) = delete;
};