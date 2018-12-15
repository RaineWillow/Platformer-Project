all:
	g++ -o game.exe src/main.cpp src/game.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

clean:
	rm game.exe
