#include "../include/window.h"
#include "../include/triangle.h"
#include "../include/cube.h"
#include <glm/gtc/type_ptr.hpp>
#include "../include/camera.h"
#include "../include/time.h"
#include "../include/skybox.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

//TODO 1. Delta time should be wrong based on implementation
//TODO 2. Moving input from camera.cpp and main.cpp to dedicated input class

void processInput(GLFWwindow *window, float deltaT, Camera &camera);
int main()
{
    Window window(800, 600);
    //Triangle triangle;
    Camera camera(window.getWindow());
    Time time;
    Cube cube;
    Skybox skybox;


    //matrix transformation test
    glm::mat4 trans = glm::mat4(1.0f);
    GLuint transformLoc;
    glm::mat4 view;
    GLuint viewLoc;
    glm::mat4 projection = glm::mat4 (1.0f);
    projection = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f, 100.0f); //projection matrix
    GLuint projectionLoc;

    //render loop
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        processInput(window.getWindow(), time.getDeltaTime(), camera);
        camera.mouse_callback(window.getWindow());

        glClearColor(1.0f, 0.25f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        cube.bindShaderProgram(cube.shaderProgram);

        //model matrix
        transformLoc = glGetUniformLocation(cube.shaderProgram, "transform");
        trans = glm::rotate(trans, time.getDeltaTime(), glm::vec3(0.0f,1.0f,0.0f));
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

        viewLoc = glGetUniformLocation(cube.shaderProgram, "view");
        view = camera.getViewMatrix();
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        projectionLoc = glGetUniformLocation(cube.shaderProgram,"projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

        cube.drawCM(cube.VAO);



        glDepthFunc(GL_LEQUAL);
        skybox.bindShaderProgram(skybox.shaderProgram);

        viewLoc = glGetUniformLocation(skybox.shaderProgram, "view");
        view = glm::mat4 (glm::mat3 (camera.getViewMatrix()));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        projectionLoc = glGetUniformLocation(skybox.shaderProgram,"projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

        skybox.drawCM(skybox.VAO);
        glDepthFunc(GL_LESS);




        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
        time.reset();
    }

    return 0;
}

void processInput(GLFWwindow *window, float deltaT, Camera &camera)
{
    camera.setCameraSpeed(3.5f * deltaT);
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.cameraMoveForward();
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.cameraMoveBackward();
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.cameraMoveRight();
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.cameraMoveLeft();
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.cameraMoveUp();
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        camera.cameraMoveDown();
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}