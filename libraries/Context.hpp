#pragma once


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"


class Context
{
    public:
        Context(const char* title, Vector2f size);

        SDL_Window* get_window();
        SDL_Renderer* get_renderer();
        const char* get_title();
        Vector2f get_size();

        SDL_Texture* load_texture(const char* file_path);
        Vector2f* get_texture_size(SDL_Texture* texture);

        void fill(Vector4f rgba);
        void blit(SDL_Texture* texture, Rect rect);

        void update_display();

        void quit();

    private:
        SDL_Window* WIN;
        SDL_Renderer* RENDERER;
        const char* title;
        Vector2f size;
};