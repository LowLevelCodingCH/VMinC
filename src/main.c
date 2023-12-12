#include "sdl_init.h"
#include "sdl_graphics.h"

int main(int argc, char *argv[]) {
    if (init_SDL("works omg", 640, 480))
        return 1;

    // example sdl code
    setDrawColor(0x00FF00FF);
    for (int i = 1; i < 479; i++) {
        setPixel(i, i);
        setPixel(i + 1, i);
        setPixel(i, i + 1);
    }
    // end example sdl code

    // Execution loop
    for (;;) {
        // run instruction

        SDL_Event e;
        SDL_WaitEventTimeout(&e, 0);

        // User requests quit
        if (e.type == SDL_QUIT)
            break;

        // Update screen
        SDL_RenderPresent(sdl_renderer);
    }

    quit_sdl();
}