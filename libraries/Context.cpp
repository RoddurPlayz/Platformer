#include "Context.hpp"


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"
#include "SpriteClasses.hpp"


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


void Context::set_title(const char* title)
{
    SDL_SetWindowTitle(WIN, title);
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


bool Context::collide_rect(Rect rect1, Rect rect2)
{
    SDL_Rect rrect1 = rect1.get_sdl_rect();
    SDL_Rect rrect2 = rect2.get_sdl_rect();
    
    if (SDL_HasIntersection(&rrect1, &rrect2))
    {
        return true;
    }
    return false;
}


void Context::move_and_slide(Player& rect1, Objects& rect2, Vector2f x_and_y)
{
    if (collide_rect(rect1.get_rect(), rect2.get_rect()))
        {
            Vector4f r1 = rect1.get_rect().get_top_left();
            Vector4f r2 = rect2.get_rect().get_top_left();
            int mi1 = std::min(r1.x + r1.z, r2.x + r2.z);
            int mi2 = std::min(r1.y + r1.w, r2.y + r2.w);
            int overlapX = std::max(0, mi1) + std::max(r1.x, r2.x);
            int overlapY = std::max(0, mi2) + std::max(r1.y, r2.y);

            if (overlapX < overlapY)
            {
                if (r1.x < r2.x) rect1.move_ip(-x_and_y.x, 0);
                else rect1.move_ip(x_and_y.x, 0);
            }

            else
            {
                if (r1.y < r2.y) rect1.move_ip(0, -x_and_y.y);
                else rect1.move_ip(0, x_and_y.y);
            }
        }
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
