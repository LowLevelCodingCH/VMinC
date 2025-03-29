#ifndef SDL_event_h
#define SDL_event_h

#include <SDL.h>
#include <stdlib.h>
#include <graphics/sdl_error.h>

typedef struct G_WriteCharEventData {
    int x, y;
    const char *c;
    Uint32 color;
} G_WriteCharEventData;

int G_sendWriteCharEvent(int x, int y, const char c[256], Uint32 color) {
    SDL_Event writeCharEvent;
    writeCharEvent.type = SDL_USEREVENT;

    G_WriteCharEventData *data = (G_WriteCharEventData*)malloc(sizeof(G_WriteCharEventData));
    data->x = x;
    data->y = y;
    data->color = color;
    data->c = c;

    writeCharEvent.user.code = 37;
    writeCharEvent.user.data1 = data;
    writeCharEvent.user.timestamp = SDL_GetTicks();

    int res = SDL_PushEvent(&writeCharEvent);

    if (res == 1) return 0;
    if (res == 0) return 1;
    else G_error();
}

#endif