#pragma once
#include <cmath>
#include <iostream>

namespace core {

class Vector3 {
public:
    double x, y, z;
    Vector3(double x = 0, double y = 0, double z = 0);
    Vector3 operator+(const Vector3 &other) const;
    Vector3 operator+(double &other) const;
    Vector3 operator-(const Vector3 &other) const;
    Vector3 operator*(const Vector3 &other) const;
    Vector3 operator*(double scalar) const;
    Vector3 operator/(double scalar) const;
    Vector3 &operator+=(const Vector3 &other);
    Vector3 &operator-=(const Vector3 &other);
    Vector3 &operator*=(double scalar);
    Vector3 &operator/=(double scalar);
    Vector3 operator-() const;
    bool operator==(const Vector3 &other) const;
    bool operator!=(const Vector3 &other) const;
    double magnitude() const;
    Vector3 normalize() const;
    double dot(const Vector3 &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Vector3 &vec);
};
} // namespace core