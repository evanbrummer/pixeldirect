TARGET = pd

all:
	g++ main.cpp -o $(TARGET) -I src/include -L src/lib -lSDL2main -lSDL2
	./$(TARGET)