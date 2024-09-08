#include "rect.h"
#include "vector.h"

namespace core {

// Constructor
Rect::Rect(Vector2 pos, int width, int height) :
        pos(pos), width(width), height(height) {}

int Rect::getWidth() const {
    return width;
}
int Rect::getHeight() const {
    return height;
}

void Rect::setWidth(int width) {
    this->width = width;
}
void Rect::setHeight(int height) {
    this->height = height;
}

// Convert to SDL_Rect
SDL_Rect Rect::toSDLRect() const {
    SDL_Rect rect = { int(pos.x), int(pos.y), int(width), int(height) };
    return rect;
}

// Check if a point is inside the rectangle
bool Rect::contains(const Vector2 &point) const {
    return (point.x >= pos.x && point.x <= pos.x + width && point.y >= pos.y && point.y <= pos.y + height);
}

// Check if two rectangles intersect
bool Rect::intersects(const Rect &other) const {
    return (pos.x < other.pos.x + other.width &&
            pos.x + width > other.pos.x &&
            pos.y < other.pos.y + other.height &&
            pos.y + height > other.pos.y);
}

// Move the rectangle by a delta
void Rect::move(const Vector2 &dir) {
    pos.x += dir.x;
    pos.y += dir.y;
}

// Scale the rectangle size by a factor
void Rect::scale(float factor) {
    width = static_cast<int>(width * factor);
    height = static_cast<int>(height * factor);
}

// Equality operator
bool Rect::operator==(const Rect &other) const {
    return (pos.x == other.pos.x && pos.y == other.pos.y && width == other.width && height == other.height);
}

// Inequality operator
bool Rect::operator!=(const Rect &other) const {
    return !(*this == other);
}

// Stream output operator for printing
std::ostream &operator<<(std::ostream &os, const Rect &rect) {
    os << "Rect(x=" << rect.pos.x << ", y=" << rect.pos.y << ", width=" << rect.width << ", height=" << rect.height << ")";
    return os;
}

} // namespace core
