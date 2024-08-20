#include <iostream>
#include "SDL.h"

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Pixel Direct", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL) {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    SDL_Event e;
    int x = 0, y = 0;
    int xv = 1, yv = 1;

    while (true) {
        
        void *pixels;
        int pitch;
        SDL_LockTexture(texture, NULL, &pixels, &pitch);

        Uint32 *pixel_ptr = (Uint32*)((Uint8*)pixels + y * pitch + x * 4);
        *pixel_ptr = SDL_MapRGBA(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), 255, 0, 0, 255);

        if (x < WIDTH) { 
            x += xv;
        } else {
            xv *= -1;
            x += xv;
        }
        if (y < HEIGHT) {
            y += yv;
        } else {
            yv *= -1;
            y += yv;
        }

        SDL_UnlockTexture(texture);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}