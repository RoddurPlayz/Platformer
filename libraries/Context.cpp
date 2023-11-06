#include "Context.hpp"


#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Math.hpp"
#include "Image.hpp"


Context::Context(Vector2f size)
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cout << "[SDL] SDL ran into an error while initializing everything!" << "\n";
        std::cout << "[SDL Error] " << SDL_GetError() << "\n";
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "[SDL_image] SDL_image ran into an error while initializing PNG image format!" << "\n";
        std::cout << "[SDL_image Error] " << IMG_GetError() << "\n";
    }

    WIN = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, 0);
    if (!WIN)
    {
        std::cout << "[SDL] SDL ran into an error while initializing the window!" << "\n";
        std::cout << "[SDL Error] " << SDL_GetError() << "\n";
    }

    RENDERER = SDL_CreateRenderer(WIN, -1, SDL_RENDERER_ACCELERATED);
}


void Context::set_caption(const char* title)
{
    SDL_SetWindowTitle(WIN, title);
}


Image Context::load_image(const char* path)
{
    Image image;
    image.image = IMG_LoadTexture(RENDERER, path);

    if (!image.image)
    {
        std::cout << "[SDL_image] SDL_image ran into an error while loading a PNG formatted file from directory \"" << path << "\"!" << "\n";
        std::cout << "[SDL_image Error] " << IMG_GetError() << "\n";
    }

    return image;
}


void Context::update()
{
    SDL_RenderPresent(RENDERER);
}


float Context::clock_tick(float FPS)
{
    double current_tick_time = SDL_GetTicks();
    dt = (current_tick_time - last_tick_time) / 1000;
    last_tick_time = current_tick_time;
    if (dt < 1000 / FPS)
    {
        SDL_Delay(1000 / FPS - dt);
    }
    
    return dt;
}


float Context::get_fps()
{
    
    return FPS;
}


void Context::fill(Vector4f rgba)
{
    SDL_RenderClear(RENDERER);
    SDL_SetRenderDrawColor(RENDERER, rgba.x, rgba.y, rgba.z, rgba.w);
}


void Context::quit()
{
    SDL_DestroyWindow(WIN);
    SDL_Quit();
}
