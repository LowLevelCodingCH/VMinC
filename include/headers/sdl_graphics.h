#ifndef SDL_GRAPHICS_h_
#define SDL_GRAPHICS_h_

#include <stdint.h>
#include <SDL.h>
#include "sdl_init.h"

int setPixelHex(uint32_t color, int x, int y) {
    if (!sdl_renderer)
        return 1;

    SDL_SetRenderDrawColor(sdl_renderer, (color & 0xFF000000) >> 24, (color & 0x00FF0000) >> 16, (color & 0x0000FF00) >> 8, color & 0x000000FF);
    SDL_RenderDrawPoint(sdl_renderer, x, y);

    return 0;
}

void setPixel(int x, int y) {
    SDL_RenderDrawPoint(sdl_renderer, x, y);
}

void setDrawColor(uint32_t color) {
    SDL_SetRenderDrawColor(sdl_renderer, (color & 0xFF000000) >> 24, (color & 0x00FF0000) >> 16, (color & 0x0000FF00) >> 8, color & 0x000000FF);
}

#endif