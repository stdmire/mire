#pragma once
#include "SDL_rect.h"
#include "vector.h"
#include <SDL.h>
#include <iostream>

namespace core {

class Rect {
public:
    Rect(Vector2 pos, int width = 0, int height = 0);
    Rect() :
            width(0), height(0), pos(0, 0) {};

    int getWidth() const;
    int getHeight() const;

    void setWidth(int width);
    void setHeight(int height);

    SDL_Rect toSDLRect() const;
    bool contains(const Vector2 &point) const;
    bool intersects(const Rect &other) const;
    void move(const Vector2 &dir);
    void scale(float factor);

    bool operator==(const Rect &other) const;
    bool operator!=(const Rect &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Rect &rect);

    Vector2 pos;

private:
    int width, height;
};

} // namespace core
