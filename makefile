# Windows: `mingw32-make -f MakeFile`

all:
	gcc src/main.c -Iinclude/sdl -Isrc -Iassets -lSDL2 -o out/main

run: all
	out/main