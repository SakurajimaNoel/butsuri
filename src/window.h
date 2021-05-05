#pragma once
#include <iostream>
#include <SDL.h>
#include <memory>
class Window
{
private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> pSdlWindow;
    SDL_Surface *pScreenSurface = nullptr;
    const u_short SCREEN_WIDTH = 640;
    const u_short SCREEN_HEIGHT = 480;
public:
    Window();
};