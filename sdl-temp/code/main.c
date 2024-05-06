#include <SDL2/SDL.h>

#include "utils/utils.h"

bool HandleEvent(SDL_Event *Event) {
  bool ShouldQuit = false;
  switch (Event->type) {
    case SDL_QUIT: {
      ShouldQuit = true;
    } break;
    case SDL_WINDOWEVENT: {
      switch (Event->window.event) {
        case SDL_WINDOWEVENT_EXPOSED: {
          SDL_Window *Window = SDL_GetWindowFromID(Event->window.windowID);
          SDL_Renderer *Renderer = SDL_GetRenderer(Window);
          SDL_RenderClear(Renderer);
          SDL_RenderPresent(Renderer);
        } break;
      }
    } break;
  }

  return ShouldQuit;
}

i32 main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *Window = SDL_CreateWindow(
    "SDL template",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640, 480,
    0
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
