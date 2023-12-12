#ifndef SDL_INIT_h_
#define SDL_INIT_h_

#include <stdio.h>
#include <SDL.h>

static SDL_Window *window;
static SDL_Renderer *sdl_renderer;

int init_SDL(char *name, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not be initialized!\r\nSDL_Error: %s\r\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow(name,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width, height,
                              SDL_WINDOW_SHOWN);

    if (!window) {
        printf("Window could not be created!\r\nSDL_Error: %s\r\n", SDL_GetError());
        return 1;
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!sdl_renderer) {
        printf("Renderer could not be created!\r\nSDL_Error: %s\r\n", SDL_GetError());
        return 1;
    }

    // Initialize renderer color black for the background
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0xFF);

    // Clear screen
    SDL_RenderClear(sdl_renderer);

    return 0;
}

int quit_sdl() {
    // Destroy renderer
    SDL_DestroyRenderer(sdl_renderer);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();

    return 0;
}

#endif