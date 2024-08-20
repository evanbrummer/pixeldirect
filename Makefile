TARGET = pd

all:
	g++ main.cpp -o $(TARGET) -I external/include -L external/lib -lSDL2main -lSDL2