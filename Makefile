CXX=g++
CFLAGS=
LIBS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image
SOURCES=src/main.cpp src/game.cpp src/core/resource_manager.cpp src/core/camera.cpp src/map/tilemap.cpp src/map/tile.cpp

all:
	$(CXX) $(CFLAGS) -o game.exe $(SOURCES) $(LIBS)

.PHONY: run
run: all
	./game.exe

.PHONY: clean
clean:
	rm -f game.exe
