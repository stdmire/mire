#include "color.h"
#include <iomanip>
#include <sstream>
namespace core {

Color::Color() :
        r(0), g(0), b(0), a(255) {}

Color::Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a) {
    setR(r);
    setG(g);
    setB(b);
    setA(a);
}

unsigned int Color::getR() const {
    return r;
}
unsigned int Color::getG() const {
    return g;
}
unsigned int Color::getB() const {
    return b;
}
unsigned int Color::getA() const {
    return a;
}

void Color::setR(unsigned int r) {
    this->r = clamp(r);
}
void Color::setG(unsigned int g) {
    this->g = clamp(g);
}
void Color::setB(unsigned int b) {
    this->b = clamp(b);
}
void Color::setA(unsigned int a) {
    this->a = clamp(a);
}

void Color::lighten(float factor) {
    r = clamp(static_cast<unsigned int>(r * factor));
    g = clamp(static_cast<unsigned int>(g * factor));
    b = clamp(static_cast<unsigned int>(b * factor));
}

void Color::darken(float factor) {
    r = clamp(static_cast<unsigned int>(r * factor));
    g = clamp(static_cast<unsigned int>(g * factor));
    b = clamp(static_cast<unsigned int>(b * factor));
}

std::string Color::toHex() const {
    std::stringstream ss;
    ss << "#" << std::hex << std::setw(2) << std::setfill('0') << r
       << std::setw(2) << std::setfill('0') << g
       << std::setw(2) << std::setfill('0') << b;
    return ss.str();
}

bool Color::operator==(const Color &other) const {
    return r == other.r && g == other.g && b == other.b && a == other.a;
}

bool Color::operator!=(const Color &other) const {
    return !(*this == other);
}

Color Color::operator+(const Color &other) const {
    return Color(
            clamp(r + other.r),
            clamp(g + other.g),
            clamp(b + other.b),
            clamp(a + other.a));
}

Color Color::operator*(float factor) const {
    return Color(
            clamp(static_cast<unsigned int>(r * factor)),
            clamp(static_cast<unsigned int>(g * factor)),
            clamp(static_cast<unsigned int>(b * factor)),
            a);
}

unsigned int Color::clamp(unsigned int value, unsigned int min, unsigned int max) const {
    return (value < min) ? min : (value > max) ? max :
                                                 value;
}

std::ostream &operator<<(std::ostream &os, const Color &color) {
    os << "Color(R=" << color.r << ", G=" << color.g << ", B=" << color.b << ", A=" << color.a << ")";
    return os;
}
} // namespace core