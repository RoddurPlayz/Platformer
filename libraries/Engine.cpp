#include "Engine.hpp"


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Context.hpp"
#include "Math.hpp"
#include "Image.hpp"


Engine::Engine()
{

}


void Engine::check_events()
{
    keys = SDL_GetKeyboardState(NULL);

    if (SDL_WaitEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            WIN.quit();
            running = false;
        }
    }
}


void Engine::update()
{
    WIN.clock_tick(60);
    std::cout << WIN.get_fps() << "\r";
}


void Engine::render()
{
    WIN.fill(Vector4f(255, 255, 255, 255));
}


void Engine::run()
{
    while (running)
    {
        this->check_events();
        this->update();
        this->render();

        WIN.update();
    }
}
