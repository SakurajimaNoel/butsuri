#include "window.h"

Window::Window(int width, int height) : SCREEN_WIDTH(width), SCREEN_HEIGHT(height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    pWindow = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Butsuri", nullptr, nullptr);
    if (pWindow == nullptr)
    {
        std::cout<<"window init failed";
        glfwTerminate();
    }
    glfwMakeContextCurrent(pWindow);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    glfwSetFramebufferSizeCallback(pWindow, Window::framebuffer_size_callback);
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0,0,width,height);
}

GLFWwindow* Window::getWindow()
{
    return pWindow;
}

Window::~Window()
{
    glfwTerminate();
}