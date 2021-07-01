#pragma once
#include <functional>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLM_SWIZZLE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Camera
{
public:
    Camera(GLFWwindow *window);
    void cameraMoveForward();
    void cameraMoveBackward();
    void cameraMoveLeft();
    void cameraMoveRight();
    void cameraMoveUp();
    void cameraMoveDown();
    void setCameraSpeed(float speed);
    glm::mat4 getViewMatrix();
    void mouse_callback(GLFWwindow *window);
    bool curCamPos();
    int oldPosX=0, oldPosZ=0, newPosX, newPosZ;
private:
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    float cameraSpeed = 0.0f;
    glm::vec3 direction;
    bool firstMouse = true;
    float lastX =400, lastY =600, xOffset, yOffset, sensitivity = 0.1f, pitch=0, yaw=-90;




};