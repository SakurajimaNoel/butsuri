#include "window.h"

Window::Window():pSdlWindow(nullptr, SDL_DestroyWindow)
{
    SDL_Init(SDL_INIT_VIDEO);
    pSdlWindow.reset(SDL_CreateWindow("Butsuri", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN));
    pScreenSurface = SDL_GetWindowSurface(pSdlWindow.get());
    SDL_FillRect(pScreenSurface,nullptr, SDL_MapRGB(pScreenSurface->format, 0xAA, 0xFF, 0xFF) );
    SDL_UpdateWindowSurface(pSdlWindow.get());
}
