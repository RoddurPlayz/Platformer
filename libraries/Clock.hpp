#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Clock
{
    public:
        void tick_begin(double FPS);
        double get_delta_time();
        void tick_end();

    private:
        int FPS;
        int desired_dt;
        int start_loop;

        double last_tick_time = 0;
        double dt = 0;
};
