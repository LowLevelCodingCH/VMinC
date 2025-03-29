#ifndef SDL_text_h
#define SDL_text_h

#include <graphics/sdl_graphics.h>
#include <graphics/sdl_init.h>
#include <string.h>

SDL_Texture *G_videomem = NULL;

/**
 * Creates a video memory texture.
 * 
 * @return `0` on success, `1` if video memory already exists. Calls `G_error` on error.
 * 
 * @param w width
 * @param h height
 */
int G_initVideomem(int w, int h) {
    if (G_videomem)
        return 1;

    G_width = w;
    G_height = h;

    G_videomem = SDL_CreateTexture(G_SDLrenderer, SDL_PIXELFORMAT_ABGR32, SDL_TEXTUREACCESS_STREAMING, w, h);

    if (!G_videomem) {
        printf("failed to initialize video memory\n");
        G_error();
    }

    return 0;
}

/**
 * Renders the video memory.
 * 
 * This stretches the video memory over the screen.
 * 
 * @warning Only call this function from the main thread.
 */
int G_render() {
    if (!G_videomem)
        return 1;

    // Draw video mem
    if (SDL_RenderCopy(G_SDLrenderer, G_videomem, NULL, NULL))
        G_error();

    // Draw on the screen
    SDL_RenderPresent(G_SDLrenderer);

    return 0;
}

/**
 * Frees video memory and deletes it.
 */
void G_deleteVideomem() {
    if (!G_videomem)
        return;

    SDL_DestroyTexture(G_videomem);

    G_videomem = NULL;
}

// note: 16x16 charsets might not be ideal
/**
 * Writes a character at the specified x and y offset (16 pixel increments).
 * 
 * @param x x character position
 * @param y y character position
 * @param c character entry in charset
 * @param color RGBA color of character
 */
void G_writeChar(int x, int y, const char c[256], Uint32 color) {
    SDL_Rect rect = { x * 16, y * 16, 16, 16 };

    char *pixels;
    int pitch;

    if (SDL_LockTexture(G_videomem, &rect, (void**)&pixels, &pitch))
        G_error();

    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            *(Uint32*)(pixels + x*4 + y*pitch) = color * c[x + y * 16];
        }  
    }

    SDL_UnlockTexture(G_videomem);
}

#endif