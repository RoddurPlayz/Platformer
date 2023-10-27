#include "Clock.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


void Clock::tick_begin(double FPS)
{
    this->FPS = FPS;
    desired_dt = 1000 / FPS;

    start_loop = SDL_GetTicks();
}


double Clock::get_delta_time()
{
    double tick_time = SDL_GetTicks();
    dt = (tick_time - last_tick_time) / 1000;
    last_tick_time = tick_time;

    return dt;
}


void Clock::tick_end()
{
    int dt = SDL_GetTicks() - start_loop;

    if (dt < desired_dt)
    {
        SDL_Delay(desired_dt - dt);
    }
}
