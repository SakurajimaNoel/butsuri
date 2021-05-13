#include "../include/window.h"
#include "../include/triangle.h"
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
int main()
{
    Window window(800, 600);
    Triangle triangle;

    //matrix transformation test
    triangle.bindShaderProgram(triangle.shaderProgram);
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians(20.0f), glm::vec3(0.0f,0.0f,1.0f));
    GLuint transformLoc = glGetUniformLocation(triangle.shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    //render loop
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        glClearColor(1.0f, 0.25f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        triangle.draw(triangle.VAO);

        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }

    return 0;
}
