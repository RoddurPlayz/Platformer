#pragma once


#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"
#include "Texture.hpp"


class SpriteClass
{
    public:
        SDL_Texture* image;
        Texture texture_utils;
        Rect rect;
};
