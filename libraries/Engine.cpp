#include "Engine.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Context.hpp"
#include "Math.hpp"
#include "Clock.hpp"
#include "SpriteClass.hpp"
#include "SpriteClasses.hpp"


Engine::Engine()
{

}


void Engine::check_events()
{
    keys = SDL_GetKeyboardState(NULL);

    if (Playerr.get_rect().get_top_left().y > 0) if (keys[SDL_SCANCODE_W]) Playerr.move_ip(0, -10);
    if (Playerr.get_rect().get_top_left().x > 0) if (keys[SDL_SCANCODE_A]) Playerr.move_ip(-10, 0);
    if (Playerr.get_rect().get_top_left().y < 600 - Playerr.get_rect().get_top_left().z) if (keys[SDL_SCANCODE_S]) Playerr.move_ip(0, 10);
    if (Playerr.get_rect().get_top_left().x < 800 - Playerr.get_rect().get_top_left().w) if (keys[SDL_SCANCODE_D]) Playerr.move_ip(10, 0);
}


void Engine::update()
{
    
}


void Engine::render()
{
    WIN.fill(Vector4f(255, 255, 255, 255));

    WIN.blit(Playerr.get_image(), Playerr.get_rect());
}


void Engine::run()
{
    while (true)
    {
        clock.tick_begin(FPS);

        dt = clock.get_delta_time();

        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                WIN.quit();
                break;
            }
        }

        check_events();
        update();

        render();
        WIN.update_display();

        clock.tick_end();
    }
}