#pragma once


struct Vector2f
{
    float x, y;

    Vector2f()
    : x(0.0f), y(0.0f)
    {}

    Vector2f(float x, float y);
};


struct Vector4f
{
    float x, y, z, w;

    Vector4f()
    : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
    {}

    Vector4f(float x, float y, float z, float w);
};
