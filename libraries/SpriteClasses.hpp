#pragma once


#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SpriteClass.hpp"


class Player : SpriteClass
{
    public:
        Player(SDL_Texture* texture, Vector2f position);

        SDL_Texture* get_image();
        Rect get_rect();
        Rect* get_rrect();

        void move_ip(float x, float y);
        void mul_move_ip(float x, float y);
        void set_position(Vector2f position);
};


class Objects : SpriteClass
{
    public:
        Objects(SDL_Texture* texture, Vector2f position);
        
        SDL_Texture* get_image();
        Rect get_rect();

        void move_ip(float x, float y);
};
