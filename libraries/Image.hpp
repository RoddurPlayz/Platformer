#pragma once


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"


struct Image
{
    SDL_Texture* image = NULL;

    SDL_Rect get_rect(Vector2f coordinates);
    Vector2f get_size();
};
