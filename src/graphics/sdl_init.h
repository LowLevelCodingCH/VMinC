#ifndef SDL_INIT_h_
#define SDL_INIT_h_

#include <stdio.h>
#include <SDL.h>
#include <graphics/sdl_error.h>

static SDL_Window *G_SDLwindow;
static SDL_Renderer *G_SDLrenderer;

static int G_width, G_height;

void G_initSDL(char *name, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL could not be initialized!\n");
        G_error();
    }

    G_width = width;
    G_height = height;

    G_SDLwindow = SDL_CreateWindow(name,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width, height,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (!G_SDLwindow) {
        printf("Window could not be created!\n");
        G_error();
    }

    // Create renderer
    G_SDLrenderer = SDL_CreateRenderer(G_SDLwindow, -1, SDL_RENDERER_ACCELERATED);
    if (!G_SDLrenderer) {
        printf("Renderer could not be created!");
        G_error();
    }
}

void G_quitSDL() {
    // Destroy renderer
    SDL_DestroyRenderer(G_SDLrenderer);

    // Destroy window
    SDL_DestroyWindow(G_SDLwindow);

    // Quit SDL
    SDL_Quit();
}

#endif