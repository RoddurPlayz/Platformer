#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"


class Texture
{
    public:
        Vector2f get_texture_size(SDL_Texture* texture);
        Rect get_texture_rect(SDL_Texture* texture);
};
