#include "Image.hpp"


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"


SDL_Rect Image::get_rect(Vector2f coordinates)
{
    SDL_Rect image_rect;
    SDL_Point size;

    if (SDL_QueryTexture(image, NULL, NULL, &size.x, &size.y) < 0)
    {
        std::cout << "[SDL] SDL ren into an error while trying to query the texture to get its size for its rect!" << "\n";
        std::cout << "[SDL Error] " << SDL_GetError() << "\n";

        return image_rect;
    }

    image_rect.x = coordinates.x;
    image_rect.y = coordinates.y;
    image_rect.w = size.x;
    image_rect.h = size.y;
    
    return image_rect;
}


Vector2f Image::get_size()
{
    Vector2f Vsize;
    SDL_Point size;

    if (SDL_QueryTexture(image, NULL, NULL, &size.x, &size.y) < 0)
    {
        std::cout << "[SDL] SDL ren into an error while trying to query the texture to get its size!" << "\n";
        std::cout << "[SDL Error] " << SDL_GetError() << "\n";

        return Vsize;
    }

    Vsize.x = size.x;
    Vsize.y = size.y;
    
    return Vsize;
}
