#ifndef SDL_GRAPHICS_h_
#define SDL_GRAPHICS_h_

#include <stdint.h>
#include <SDL.h>
#include "sdl_init.h"

/**
 * Sets a pixel at the current render target.
 * 
 * @param x x position
 * @param y y position
 */
void G_setPixel(int x, int y) {
    if (SDL_RenderDrawPoint(G_SDLrenderer, x, y))
        G_error();
}

/**
 * Sets the global draw color.
 * 
 * The color is reset when i.e. the screen rendering routine is ran (it clears the screen).
 * 
 * @param x x position
 * @param y y position
 */
void G_setDrawColor(uint32_t color) {
    if (SDL_SetRenderDrawColor(G_SDLrenderer, (color & 0xFF000000) >> 24, (color & 0x00FF0000) >> 16, (color & 0x0000FF00) >> 8, color & 0x000000FF))
        G_error();
}

/**
 * Sets rendering scale such that the video memory takes up the whole window.
 */
void G_strechScreen() {
    int width, height;
    SDL_GetWindowSize(G_SDLwindow, &width, &height);

    float scaleX = (float)width / G_width;
    float scaleY = (float)height / G_height;
    if (SDL_RenderSetScale(G_SDLrenderer, scaleX, scaleY))
        G_error();
}

#endif