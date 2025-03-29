#ifndef SDL_ERROR_h_
#define SDL_ERROR_h_

#include <stdio.h>
#include <SDL.h>

void G_error() {
    const char* error = SDL_GetError();

    printf("SDL error:\n%s", error);

    SDL_Quit();

    exit(3);
}

#endif