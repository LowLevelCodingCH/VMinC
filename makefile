# Windows: `mingw32-make -f MakeFile`

all:
	@make build
	@make run

build:
	@echo "CC main"
	@gcc src/main.c -Iinclude/sdl -Isrc -Iassets -lSDL2 -o main

clean: 
	@rm ./main

run: build
	@./main
