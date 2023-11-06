#pragma once


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Context.hpp"
#include "Math.hpp"
#include "Image.hpp"


class Engine
{
    public:
        Engine();

        void check_events();
        void update();
        void render();
        void run();

    private:
        Context WIN = Context(Vector2f(800, 600));
        bool running = true;

        SDL_Event event;
        const Uint8* keys;
};
