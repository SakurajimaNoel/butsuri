#include "../include/camera.h"

Camera::Camera(GLFWwindow *window)
{
    //glfwSetCursorPosCallback(window, mouse_callback);
}

void Camera::cameraMoveForward()
{
    cameraPos += cameraSpeed * cameraFront;
}
void Camera::cameraMoveBackward()
{
    cameraPos -= cameraSpeed * cameraFront;
}
void Camera::cameraMoveLeft()
{
    cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}
void Camera::cameraMoveRight()
{
    cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}
void Camera::cameraMoveUp()
{
    cameraPos += cameraSpeed * cameraUp;
}
void Camera::cameraMoveDown()
{
    cameraPos -= cameraSpeed * cameraUp;
}
void Camera::setCameraSpeed(float speed)
{
    cameraSpeed = speed;
}
glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
void Camera::mouse_callback(GLFWwindow *window)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    xOffset = xpos - lastX;
    yOffset = ypos - lastY;
    lastX = xpos;
    lastY = ypos;

    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw = glm::mod(yaw + xOffset, 360.0f);
    pitch += yOffset;

    if(pitch > 89.0f) pitch = 89.0f;
    if(pitch <-89.0f) pitch = -89.0f;

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = -sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw) * cos(glm::radians(pitch)));
    cameraFront = glm::normalize(direction);
}
bool Camera::curCamPos()
{
    newPosX = cameraPos.x;
    newPosZ = cameraPos.z;
    if (newPosX > oldPosX + 16 || newPosX< oldPosX - 16 || newPosZ> oldPosZ + 16 || newPosZ < oldPosZ - 16)
    {
        oldPosX = newPosX;
        oldPosZ = newPosZ;
        return true;
    }
    return false;
}