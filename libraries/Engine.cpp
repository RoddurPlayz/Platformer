#include "Engine.hpp"


#include <vector>

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

    for (Objects obj: objects)
    {
        WIN.collide_rect(Playerr.get_rect(), obj.get_rect(), axis);

        if(axis.x) Playerr.move_ip(0, 0);
        else if (!(axis.x)) if (Playerr.get_rect().get_top_left().y > 0) if (keys[SDL_SCANCODE_W]) Playerr.move_ip(0, -10);

        if(axis.y) Playerr.move_ip(0, 0);
        else if (!(axis.y)) if (Playerr.get_rect().get_top_left().x > 0) if (keys[SDL_SCANCODE_A]) Playerr.move_ip(-10, 0);

        if(axis.z) Playerr.move_ip(0, 0);
        else if (!(axis.z)) if (Playerr.get_rect().get_top_left().y < 600 - Playerr.get_rect().get_top_left().z) if (keys[SDL_SCANCODE_S]) Playerr.move_ip(0, 10);

        if(axis.w) Playerr.move_ip(0, 0);
        else if (!(axis.w)) if (Playerr.get_rect().get_top_left().x < 800 - Playerr.get_rect().get_top_left().w) if (keys[SDL_SCANCODE_D]) Playerr.move_ip(10, 0);


        // WIN.move_and_slide(Playerr, obj, Vector2f(10, 10));
    }
}


void Engine::update()
{
    std::cout << "x: " << Playerr.get_rect().get_center().x << ", " << "y: " << Playerr.get_rect().get_center().y << "\r";

    for (Objects obj: objects)
    {
        if (WIN.collide_rect(Playerr.get_rect(), obj.get_rect(), axis))
        {
            WIN.set_title("Collided!");
        }

        else
        {
            WIN.set_title("Not Collided!");
        }
    }
}


void Engine::render()
{
    WIN.fill(Vector4f(255, 255, 255, 255));

    WIN.blit(Playerr.get_image(), Playerr.get_rect());

    for (Objects obj: objects)
    {
        WIN.blit(obj.get_image(), obj.get_rect());
    }
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