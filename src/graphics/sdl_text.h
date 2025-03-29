#ifndef SDL_text_h
#define SDL_text_h

#include <graphics/sdl_graphics.h>

void G_writeChar(char c, int x, int y, char** charset) {
    for (int j = 0; j < 16; j++) {
        for (int k = 0; k < 16; k++) {
            G_setDrawColor(0x00FF00FF * charset[i][j + k * 16]);

            G_setPixel(j + x * 16, k + y * 16);
        }
    }
}

#endif