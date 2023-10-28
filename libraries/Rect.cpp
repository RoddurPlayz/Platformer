#include "Rect.hpp"


#include <SDL2/SDL.h>

#include "Math.hpp"


Rect::Rect()
{
    rtop_left = Vector4f();
    rtop_right = Vector4f(rtop_left.x + rtop_left.w, rtop_left.y, rtop_left.z, rtop_left.w);

    rcenter = Vector4f(rtop_left.x + rtop_left.z / 2, rtop_left.y + rtop_left.w / 2, rtop_left.z, rtop_left.w);

    rbottom_left = Vector4f(rtop_left.x, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
    rbottom_right = Vector4f(rtop_left.x + rtop_left.z, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
}


Rect::Rect(Vector4f pos_and_size)
{
    rtop_left = pos_and_size;
    rtop_right = Vector4f(rtop_left.x + rtop_left.w, rtop_left.y, rtop_left.z, rtop_left.w);

    rcenter = Vector4f(rtop_left.x + rtop_left.z / 2, rtop_left.y + rtop_left.w / 2, rtop_left.z, rtop_left.w);

    rbottom_left = Vector4f(rtop_left.x, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
    rbottom_right = Vector4f(rtop_left.x + rtop_left.z, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
}


Vector4f Rect::get_top_left()
{
    return rtop_left;
}


Vector4f Rect::get_top_right()
{
    return rtop_right;
}


Vector4f Rect::get_center()
{
    return rcenter;
}


Vector4f Rect::get_bottom_left()
{
    return rbottom_left;
}


Vector4f Rect::get_bottom_right()
{
    return rbottom_right;
}


void Rect::set_top_left(Vector4f pos_and_size)
{
    rtop_left = pos_and_size;
    rtop_right = Vector4f(rtop_left.x + rtop_left.w, rtop_left.y, rtop_left.z, rtop_left.w);

    rcenter = Vector4f(rtop_left.x + rtop_left.z / 2, rtop_left.y + rtop_left.w / 2, rtop_left.z, rtop_left.w);

    rbottom_left = Vector4f(rtop_left.x, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
    rbottom_right = Vector4f(rtop_left.x + rtop_left.z, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
}


void Rect::set_top_right(Vector4f pos_and_size)
{
    rtop_right = pos_and_size;
    rtop_left = Vector4f(rtop_left.x - rtop_left.w, rtop_left.y, rtop_left.z, rtop_left.w);

    rcenter = Vector4f(rtop_left.x + rtop_left.z / 2, rtop_left.y + rtop_left.w / 2, rtop_left.z, rtop_left.w);

    rbottom_left = Vector4f(rtop_left.x, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
    rbottom_right = Vector4f(rtop_left.x + rtop_left.z, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
}


void Rect::set_center(Vector4f pos_and_size)
{
    rcenter = pos_and_size;

    rtop_left = Vector4f(rcenter.x - rcenter.z / 2, rcenter.y - rcenter.w / 2, rcenter.z, rcenter.w);
    rtop_right = Vector4f(rtop_left.x + rtop_left.w, rtop_left.y, rtop_left.z, rtop_left.w);

    rbottom_left = Vector4f(rtop_left.x, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
    rbottom_right = Vector4f(rtop_left.x + rtop_left.z, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
}


void Rect::set_bottom_left(Vector4f pos_and_size)
{
    rbottom_left = pos_and_size;

    rtop_left = Vector4f(rbottom_left.x - rbottom_left.z, rbottom_left.y, rbottom_left.z, rbottom_left.w);
    rtop_right = Vector4f(rtop_left.x + rtop_left.w, rtop_left.y, rtop_left.z, rtop_left.w);

    rcenter = Vector4f(rtop_left.x + rtop_left.z / 2, rtop_left.y + rtop_left.w / 2, rtop_left.z, rtop_left.w);

    rbottom_right = Vector4f(rtop_left.x + rtop_left.z, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
}


void Rect::set_bottom_right(Vector4f pos_and_size)
{
    rbottom_right = pos_and_size;

    rtop_left = Vector4f(rbottom_right.x - rbottom_right.z, rbottom_right.y - rbottom_right.w, rbottom_right.z, rbottom_right.w);
    rtop_right = Vector4f(rtop_left.x + rtop_left.w, rtop_left.y, rtop_left.z, rtop_left.w);

    rcenter = Vector4f(rtop_left.x + rtop_left.z / 2, rtop_left.y + rtop_left.w / 2, rtop_left.z, rtop_left.w);

    rbottom_left = Vector4f(rtop_left.x + rtop_left.z, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
}


SDL_Rect Rect::get_sdl_rect()
{
    const float x = rtop_left.x;
    const float y = rtop_left.y;
    const float w = rtop_left.z;
    const float h = rtop_left.w;

    SDL_Rect srect;
    srect.x = x;
    srect.y = y;
    srect.w = w;
    srect.h = h;

    return srect;
}


void Rect::move_ip(float x, float y)
{
    rtop_left.x += x;
    rtop_left.y += y;
    rtop_right = Vector4f(rtop_left.x + rtop_left.w, rtop_left.y, rtop_left.z, rtop_left.w);

    rcenter = Vector4f(rtop_left.x + rtop_left.z / 2, rtop_left.y + rtop_left.w / 2, rtop_left.z, rtop_left.w);

    rbottom_left = Vector4f(rtop_left.x, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
    rbottom_right = Vector4f(rtop_left.x + rtop_left.z, rtop_left.y + rtop_left.w, rtop_left.z, rtop_left.w);
}
