#include "SpriteClasses.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SpriteClass.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "Texture.hpp"


Player::Player(SDL_Texture* texture)
{
    image = texture;
    rect = texture_utils.get_texture_rect(texture);
}


SDL_Texture* Player::get_image()
{
    return image;
}


Rect Player::get_rect()
{
    return rect;
}


void Player::move_ip(float x, float y)
{
    rect.move_ip(x, y);
}


Objects::Objects(SDL_Texture* texture, Rect rect)
{
    image = texture;
    this->rect = rect;
}


SDL_Texture* Objects::get_image()
{
    return image;
}


Rect Objects::get_rect()
{
    return rect;
}


void Objects::move_ip(float x, float y)
{
    rect.move_ip(x, y);
}
