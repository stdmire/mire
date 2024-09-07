#pragma once
#include <SDL.h>
#include <iostream>

namespace core {

class Rect {
public:
    // Constructors
    Rect(int x = 0, int y = 0, int width = 0, int height = 0);

    // Getters
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    // Setters
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);

    // Utility methods
    SDL_Rect toSDLRect() const; // Convert to SDL_Rect
    bool contains(int px, int py) const; // Check if a point is inside the rectangle
    bool intersects(const Rect &other) const; // Check for rectangle intersection
    void move(int dx, int dy); // Move the rectangle by a delta
    void scale(float factor); // Scale the rectangle size by a factor

    // Operator overloads
    bool operator==(const Rect &other) const;
    bool operator!=(const Rect &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Rect &rect);

private:
    int x, y, width, height;
};

} // namespace core
