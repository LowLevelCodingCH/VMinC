#include "graphics/sdl_init.h"
#include "graphics/sdl_graphics.h"
#include "graphics/sdl_error.h"
#include "graphics/sdl_videomem.h"
#include "graphics/sdl_event.h"

#include "charset_debug.c"
#include "charset.c"

#include <stdlib.h>
#include <string.h>

#include <pthread.h>

static int fps = 25;
static pthread_t emulator_thread;

void quit() {
    // Delete video memory
    G_deleteVideomem();
    
    G_quitSDL();

    pthread_join(emulator_thread, NULL);
    
    exit(0);
}

void handleEvent(SDL_Event e) {
    // User requests quit
    if (e.type == SDL_QUIT)
        quit();
    else if (e.type == SDL_KEYDOWN)
        {} // handle keydown
    else if (e.type == SDL_KEYUP)
        {} // handle keyup
    else if (e.type == SDL_USEREVENT) {
        if (e.user.code == 37) {
            G_WriteCharEventData *data = e.user.data1;

            G_writeChar(data->x, data->y, data->c, data->color);

            free(data);
        }
    }
}

void* emulate() {
    while (G_videomem) {
        // implement emulator here
        SDL_Delay(10);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    G_initSDL("works lessgo", 640, 480);

    // example sdl code
    G_initVideomem(640, 480);
    
    int xOffset = 0, yOffset = 0; 

    for (int i = 0; i < 96; i++) {
        G_writeChar(xOffset, yOffset, charset[i], 0x00FF00FF);

        if (xOffset++ == 39) {
            xOffset = 0;
            yOffset++;
        }
    }

    yOffset += 2;
    xOffset = 0;

    for (int i = 0; i < 96; i++) {
        G_writeChar(xOffset, yOffset, charset_debug[i], 0x00FF00FF);

        if (xOffset++ == 39) {
            xOffset = 0;
            yOffset++;
        }
    }

    // end example sdl code

    pthread_create(&emulator_thread, NULL, emulate, NULL);

    // Execution loop
    for (;;) {
        Uint64 ticksStart = SDL_GetTicks64();

        SDL_Event event;
        while (SDL_PollEvent(&event))
            handleEvent(event);

        G_render();

        Uint64 ticksEnd = SDL_GetTicks64();

        Uint64 ticksPassed = ticksEnd - ticksStart;
        Uint64 ticksLeft = ticksPassed * 1000 / fps;

        SDL_Delay(ticksLeft);
    }

    quit();
}