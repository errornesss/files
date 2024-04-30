#include <SDL2/SDL.h>
// #include <stdio.h>

#include "utils/utils.h"

bool HandleEvent(SDL_Event *Event) {
    bool ShouldQuit = false;
    switch (Event->type) {
        case SDL_QUIT: {
            ShouldQuit = true;
        } break;
    }

    return ShouldQuit;
}

i32 main(int argc, char *argv[]) {
    SDL_Window *Window = SDL_CreateWindow(
        "SDL template",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        SDL_WINDOW_RESIZABLE
    );

    if (Window) {
        SDL_Renderer *Renderer = SDL_CreateRenderer(Window, -1, 0);
        if (Renderer) {
            for (;;) {
                SDL_Event Event;
                SDL_WaitEvent(&Event);
                if (HandleEvent(&Event)) {
                    break;
                }
            }
        } else {}
    } else {}

    
    SDL_Quit();
    return 0;
}
