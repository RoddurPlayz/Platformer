#pragma once


#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Math.hpp"
#include "Image.hpp"


class Context
{
    public:
        Context(Vector2f size);

        void set_caption(const char* title);

        Image load_image(const char* path);

        void update();

        float clock_tick(float FPS);
        float get_fps();

        void fill(Vector4f rgba);

        void quit();

    private:
        SDL_Window* WIN;
        SDL_Renderer* RENDERER;

        double dt = 0;
        double last_tick_time = 0;

        float FPS = 0;
};
