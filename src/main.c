#include "graphics/sdl_init.h"
#include "graphics/sdl_graphics.h"
#include "graphics/sdl_error.h"
#include "graphics/sdl_text.h"
#include "charset_debug.c"
#include "charset.c"

int main(int argc, char *argv[]) {
    G_initSDL("works lessgo", 640, 480);

    // example sdl code
    G_initVideomem(640, 480);
    G_useVideomem();

    G_setDrawColor(0x00FF00FF);
    
    int xOffset = 0, yOffset = 0; 

    for (int i = 0; i < 96; i++) {
        G_writeChar(i, xOffset, yOffset, charset);

        if (xOffset++ == 39) {
            xOffset = 0;
            yOffset++;
        }
    }

    yOffset += 2;
    xOffset = 0;

    for (int i = 0; i < 96; i++) {
        G_writeChar(i, xOffset, yOffset, charset_debug);

        if (xOffset++ == 39) {
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

        G_render();
    }

    G_deleteVideomem();

    G_quitSDL();
}