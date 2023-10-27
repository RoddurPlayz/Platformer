#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "libraries/Context.hpp"
#include "libraries/Math.hpp"
#include "libraries/Engine.hpp"


int main(int argc, char *argv[])
{
    Engine engine;
    engine.run();

    return 0;
}
