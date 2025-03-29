#ifndef SDL_text_h
#define SDL_text_h

#include <graphics/sdl_graphics.h>

SDL_Texture *G_videomem = NULL;

// note: 16x16 charsets might not be ideal
/**
 * Writes a character at the specified x and y offset (16 pixel increments).
 * 
 * @param c character index in charset (not ASCII value)
 * @param x x character position
 * @param y y character position
 * @param charset the charset to be used
 */
void G_writeChar(char c, int x, int y, const char charset[][256]) {
    for (int j = 0; j < 16; j++) {
        for (int k = 0; k < 16; k++) {
            G_setDrawColor(0x00FF00FF * charset[c][j + k * 16]);

            G_setPixel(j + x * 16, k + y * 16);
        }
    }
}

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

    G_videomem = SDL_CreateTexture(G_SDLrenderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, w, h);

    if (!G_videomem) {
        printf("failed to initialize video memory\n");
        G_error();
    }

    return 0;
}

/**
 * Sets the video memory as a render target.
 * 
 * @return `0` on success, `1` if video memory doesn't exist. Calls `G_error` on error.
 */
int G_useVideomem() {
    if (!G_videomem)
        return 1;

    if (SDL_SetRenderTarget(G_SDLrenderer, G_videomem))
        G_error();

    return 0;
}

/**
 * Renders the video memory.
 * 
 * This stretches the video memory over the screen.
 */
int G_render() {
    if (!G_videomem)
        return 1;

    // Update screen
    G_strechScreen();

    if (SDL_RenderCopy(G_SDLrenderer, G_videomem, NULL, NULL))
        G_error();

    SDL_RenderPresent(G_SDLrenderer);

    if (SDL_SetRenderTarget(G_SDLrenderer, NULL))
        G_error();

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

#endif