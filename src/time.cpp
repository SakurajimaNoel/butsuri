#include "../include/time.h"

float Time::getCurrentTime()
{
    return glfwGetTime();
}

float Time::getDeltaTime()
{
    curTime = glfwGetTime();
    deltaTime = curTime - prevTime;
    return deltaTime;
}

void Time::reset()
{
    prevTime = curTime;
}