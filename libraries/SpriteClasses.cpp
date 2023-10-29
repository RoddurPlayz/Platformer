#include "SpriteClasses.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SpriteClass.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "Texture.hpp"


Player::Player(SDL_Texture* texture, Vector2f position)
{
    image = texture;
    rect = texture_utils.get_texture_rect(texture);
    rect.set_top_left(Vector4f(position.x, position.y, texture_utils.get_texture_size(texture).x, texture_utils.get_texture_size(texture).y));
}


SDL_Texture* Player::get_image()
{
    return image;
}


Rect Player::get_rect()
{
    return rect;
}


Rect* Player::get_rrect()
{
    return &rect;
}


void Player::move_ip(float x, float y)
{
    rect.move_ip(x, y);
}


void Player::mul_move_ip(float x, float y)
{
    rect.mul_move_ip(x, y);
}


void Player::set_position(Vector2f position)
{
    rect.set_top_left(Vector4f(position.x, position.y, rect.get_top_left().z, rect.get_top_left().w));
}


Objects::Objects(SDL_Texture* texture, Vector2f position)
{
    image = texture;
    rect = texture_utils.get_texture_rect(texture);
    rect.set_top_left(Vector4f(position.x, position.y, texture_utils.get_texture_size(texture).x, texture_utils.get_texture_size(texture).y));
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
