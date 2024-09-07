#pragma once
#include <iostream>
#include <string>

namespace core {
class Color {
public:
    // Constructors
    Color();
    Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a = 255);

    // Getter methods
    unsigned int getR() const;
    unsigned int getG() const;
    unsigned int getB() const;
    unsigned int getA() const;

    // Setter methods
    void setR(unsigned int r);
    void setG(unsigned int g);
    void setB(unsigned int b);
    void setA(unsigned int a);

    void lighten(float factor); // Lighten the color by a factor
    void darken(float factor); // Darken the color by a factor
    std::string toHex() const; // Convert color to hex string

    // Operator overloads
    bool operator==(const Color &other) const;
    bool operator!=(const Color &other) const;
    Color operator+(const Color &other) const;
    Color operator*(float factor) const;

    friend std::ostream &operator<<(std::ostream &os, const Color &color);

private:
    unsigned int r, g, b, a;

    // Utility function to clamp values between 0 and 255
    unsigned int clamp(unsigned int value, unsigned int min = 0, unsigned int max = 255) const;
};
} // namespace core