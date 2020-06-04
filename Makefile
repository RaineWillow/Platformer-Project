CXX=g++
CFLAGS=
LIBS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image

SOURCES=src/main.cpp src/game.cpp
CORE=src/core/resource_manager.cpp src/core/camera.cpp
MAP=src/map/tilemap.cpp src/map/tile.cpp
UTILS=src/utils/controller.cpp
GUI=src/gui/widget.cpp src/gui/g_button.cpp

all:
	$(CXX) $(CFLAGS) -o game.exe $(SOURCES) $(CORE) $(MAP) $(UTILS) $(LIBS)

.PHONY: run
run: all
	./game.exe

.PHONY: clean
clean:
	rm -f game.exe
