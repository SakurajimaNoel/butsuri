#include "window.h"

int main(int argc, char *args[])
{
    Window window;
    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
    SDL_Quit();
    return 0;
}