#include "window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    Window window(800, 600);

    //render loop
    while(!glfwWindowShouldClose(window.getWindow()))
    {
        glClearColor(1.0f,0.25f,0.5f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(window.getWindow());
    }

    return 0;
}
