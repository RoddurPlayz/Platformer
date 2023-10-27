#include "Texture.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"


Vector2f Texture::get_texture_size(SDL_Texture* texture)
{
    SDL_Point size;
    SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
    Vector2f vec_size = Vector2f(size.x, size.y);

    return vec_size;
}


Rect Texture::get_texture_rect(SDL_Texture* texture)
{
    SDL_Point size;
    SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
    Rect texture_rect = Rect(Vector4f(0, 0, size.x, size.y));

    return texture_rect;
}