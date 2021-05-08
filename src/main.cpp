#include "../include/window.h"
#include "../include/triangle.h"


int main()
{
    Window window(800, 600);
    Triangle triangle;

    //render loop
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        glClearColor(1.0f, 0.25f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        triangle.bindShaderProgram(triangle.shaderProgram);
        triangle.draw(triangle.VAO);

        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }

    return 0;
}
