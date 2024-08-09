all:
	g++ main.cpp -o pd -I src/include -L src/lib -lmingw32 -lSDL2main -lSDL2