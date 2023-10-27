#include "Context.hpp"


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"


Context::Context(const char* title, Vector2f size)
{
    this->title = title;
    this->size = size;

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "[SDL] SDL ran into an error while initializing video." << "\n";
        std::cout << "[SDL Error] " << SDL_GetError;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "[SDL_image] SDL_image ran into an error while initializing PNG." << "\n";
        std::cout << "[SDL_image Error] " << SDL_GetError;
    }

    WIN = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, SDL_WINDOW_SHOWN);
    if (WIN == NULL)
    {
        std::cout << "[SDL] SDL ran into an error while initializing the window." << "\n";
        std::cout << "[SDL Error] " << SDL_GetError;
    }

    RENDERER = SDL_CreateRenderer(WIN, -1, SDL_RENDERER_ACCELERATED);
}


SDL_Window* Context::get_window()
{
    return WIN;
}


SDL_Renderer* Context::get_renderer()
{
    return RENDERER;
}


const char* Context::get_title()
{
    return title;
}


Vector2f Context::get_size()
{
    return size;
}


SDL_Texture* Context::load_texture(const char* file_path)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(RENDERER, file_path);

    if (texture == NULL)
    {
        std::cout << "[SDL_image] SDL_image ran into an error while loading a PNG formated texture from path: " << file_path << "\n";
        std::cout << "[SDL_image ERROR] " << SDL_GetError() << "\n";
    }

    return texture;
}


void Context::fill(Vector4f rgba)
{
    SDL_RenderClear(RENDERER);
    SDL_SetRenderDrawColor(RENDERER, rgba.x, rgba.y, rgba.z, rgba.w);
}


void Context::blit(SDL_Texture* texture, Rect rect)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = rect.get_top_left().z;
    src.h = rect.get_top_left().w;

    SDL_Rect dst;
    dst.x = rect.get_top_left().x;
    dst.y = rect.get_top_left().y;
    dst.w = rect.get_top_left().z;
    dst.h = rect.get_top_left().w;

    SDL_RenderCopy(RENDERER, texture, &src, &dst);
}


void Context::update_display()
{
    SDL_RenderPresent(RENDERER);
}


void Context::quit()
{
    SDL_DestroyWindow(WIN);
    SDL_Quit();
}
