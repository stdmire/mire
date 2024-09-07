#include "rect.h"

namespace core {

// Constructor
Rect::Rect(int x, int y, int width, int height) :
        x(x), y(y), width(width), height(height) {}

// Getter methods
int Rect::getX() const {
    return x;
}
int Rect::getY() const {
    return y;
}
int Rect::getWidth() const {
    return width;
}
int Rect::getHeight() const {
    return height;
}

// Setter methods
void Rect::setX(int x) {
    this->x = x;
}
void Rect::setY(int y) {
    this->y = y;
}
void Rect::setWidth(int width) {
    this->width = width;
}
void Rect::setHeight(int height) {
    this->height = height;
}

// Convert to SDL_Rect
SDL_Rect Rect::toSDLRect() const {
    SDL_Rect rect = { x, y, width, height };
    return rect;
}

// Check if a point is inside the rectangle
bool Rect::contains(int px, int py) const {
    return (px >= x && px <= x + width && py >= y && py <= y + height);
}

// Check if two rectangles intersect
bool Rect::intersects(const Rect &other) const {
    return (x < other.x + other.width &&
            x + width > other.x &&
            y < other.y + other.height &&
            y + height > other.y);
}

// Move the rectangle by a delta
void Rect::move(int dx, int dy) {
    x += dx;
    y += dy;
}

// Scale the rectangle size by a factor
void Rect::scale(float factor) {
    width = static_cast<int>(width * factor);
    height = static_cast<int>(height * factor);
}

// Equality operator
bool Rect::operator==(const Rect &other) const {
    return (x == other.x && y == other.y && width == other.width && height == other.height);
}

// Inequality operator
bool Rect::operator!=(const Rect &other) const {
    return !(*this == other);
}

// Stream output operator for printing
std::ostream &operator<<(std::ostream &os, const Rect &rect) {
    os << "Rect(x=" << rect.x << ", y=" << rect.y << ", width=" << rect.width << ", height=" << rect.height << ")";
    return os;
}

} // namespace core
