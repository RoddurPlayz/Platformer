#pragma once


#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Context.hpp"
#include "Math.hpp"
#include "Clock.hpp"
#include "SpriteClass.hpp"
#include "SpriteClasses.hpp"


class Engine
{
    public:
        Engine();

        void check_events();
        void update();
        void render();
        void run();
    
    private:
        const char* title = "TEST";
        Vector2f size = Vector2f(800, 600);
        Context WIN = Context(title, size);
        SDL_Event event;
        const Uint8* keys;
        double FPS = 60;

        Clock clock;

        double dt;

        SDL_Texture* grass_texture = WIN.load_texture("assets/textures/ground_grass_1.png");
        Player Playerr = Player(grass_texture);

        std::vector<Objects> objects = {
            Objects(grass_texture, Rect(Vector4f(800 / 2 - 32, 600 / 2 - 32, 32, 32)))
        };
};
