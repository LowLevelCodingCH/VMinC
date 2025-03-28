#include "graphics/sdl_init.h"
#include "graphics/sdl_graphics.h"
#include "graphics/sdl_error.h"
#include "charset_debug.c"
#include "charset.c"

int main(int argc, char *argv[]) {
    G_initSDL("works lessgo", 640, 480);

    // example sdl code
    SDL_Texture *videomem = SDL_CreateTexture(G_SDLrenderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, 640, 480);

    if (!videomem)
        G_error();

    if (SDL_SetRenderTarget(G_SDLrenderer, videomem))
        G_error();

    G_setDrawColor(0x00FF00FF);
    
    int xOffset = 0, yOffset = 0; 

    for (int i = 0; i < 96; i++) {
        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 16; k++) {
                G_setDrawColor(0x00FF00FF * charset_debug[i][j + k * 16]);

                G_setPixel(j + xOffset * 16, k + yOffset * 16);
            }
        }
        if (xOffset++ == 40) {
            xOffset = 0;
            yOffset++;
        }
    }

    yOffset += 2;
    xOffset = 0;

    for (int i = 0; i < 96; i++) {
        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 16; k++) {
                G_setDrawColor(0x00FF00FF * charset[i][j + k * 16]);

                G_setPixel(j + xOffset * 16, k + yOffset * 16);
            }
        }
        if (xOffset++ == 40) {
            xOffset = 0;
            yOffset++;
        }
    }

    // end example sdl code

    // Execution loop
    for (;;) {
        // run instruction

        SDL_Event e;
        if (!SDL_WaitEventTimeout(&e, 1000/60))
            G_error();

        // User requests quit
        if (e.type == SDL_QUIT)
            break;
        
        if (e.type == SDL_KEYDOWN)
            {} // handle keydown
        if (e.type == SDL_KEYUP)
            {} // handle keyup

        // Update screen
        G_strechScreen();

        if (SDL_RenderCopy(G_SDLrenderer, videomem, NULL, NULL))
            G_error();

        SDL_RenderPresent(G_SDLrenderer);

        if (SDL_SetRenderTarget(G_SDLrenderer, NULL))
            G_error();

        // Draw the texture
        if (SDL_RenderCopy(G_SDLrenderer, videomem, NULL, NULL))
            G_error();

        // Draw on the screen
        SDL_RenderPresent(G_SDLrenderer);
    }

    SDL_DestroyTexture(videomem);

    G_quitSDL();
}