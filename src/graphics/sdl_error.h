#ifndef SDL_ERROR_h_
#define SDL_ERROR_h_

#include <stdio.h>
#include <SDL.h>

#ifndef G_SDL_ERR_EXITCODE 
#define G_SDL_ERR_EXITCODE 3
#endif

/**
 * Prints last SDL error and exits with exit code at `G_SDL`
 */
void G_error() {
    const char* error = SDL_GetError();

    printf("what\n");
    printf("SDL error:\n%s\n", error);

    SDL_Quit();

    exit(G_SDL_ERR_EXITCODE);
}

#endif