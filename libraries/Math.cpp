#include "Math.hpp"


#include <iostream>


Vector2f::Vector2f(float x, float y)
{
    this->x = x;
    this->y = y;
}


void Vector2f::move_ip(float x, float y)
{
    this->x += x;
    this->y += y;
}


std::string Vector2f::print(char end)
{
    std::cout << "{" << "x: " + std::to_string(x) << ", " << "y: " << std::to_string(y) << "}" << end;
}


Vector3f::Vector3f(float x, float y, float z)
{
    this->x = x;
    this->y = y;
}


void Vector3f::move_ip(float x, float y, float z)
{
    this->x += x;
    this->y += y;
    this->z += z;
}


std::string Vector3f::print(char end)
{
    std::cout << "{" << "x: " + std::to_string(x) << ", " << "y: " << std::to_string(y) << ", " << "z: " << std::to_string(z) << "}" << end;
}


Vector4f::Vector4f(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}


void Vector4f::move_ip(float x, float y, float z, float w)
{
    this->x += x;
    this->y += y;
    this->z += z;
    this->w += w;
}


std::string Vector4f::print(char end)
{
    std::cout << "{" << "x: " + std::to_string(x) << ", " << "y: " << std::to_string(y) << ", " << "z: " << std::to_string(z) << ", " << "w: " << std::to_string(w) << "}" << end;
}
