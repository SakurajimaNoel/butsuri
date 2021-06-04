#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//TODO this class is probably broken

class Time
{
public:

    float getCurrentTime();
    float getDeltaTime();
    void reset();

private:
    float curTime, prevTime, deltaTime =0;

};