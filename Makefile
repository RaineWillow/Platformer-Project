CXX=g++
CFLAGS=
LIBS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all:
	$(CXX) $(CFLAGS) -o game.exe src/main.cpp src/game.cpp src/core/resource_manager.cpp $(LIBS)

.PHONY: run
run: all
	./game.exe

.PHONY: clean
clean:
	rm -f game.exe
