#include "vector.h"
#include "log.h"

namespace core {
Vector3::Vector3(double x, double y, double z) :
        x(x), y(y), z(z) {
}
Vector3 Vector3::operator+(const Vector3 &other) const {
    log::out("called Vector3 Vector3::operator+(const Vector3 &other) const");
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator+(double &other) const {
    log::out("called Vector3 Vector3::operator+(double &other) const");
    return Vector3(x + other, y + other, z + other);
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    log::out("called Vector3 Vector3::operator-(const Vector3 &other) const");
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(const Vector3 &other) const {
    log::out("called Vector3 Vector3::operator*(const Vector3 &other) const");
    return Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3 Vector3::operator*(double scalar) const {
    log::out("called Vector3 Vector3::operator*(double scalar) const");
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(double scalar) const {
    log::out("called Vector3 Vector3::operator/(double scalar) const");
    if (scalar != 0) {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }
    throw;
}

Vector3 &Vector3::operator+=(const Vector3 &other) {
    log::out("called Vector3 &Vector3::operator+=(const Vector3 &other)");
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &other) {
    log::out("called Vector3 &Vector3::operator-=(const Vector3 &other)");
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3 &Vector3::operator*=(double scalar) {
    log::out("called Vector3 &Vector3::operator*=(double scalar)");
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector3 &Vector3::operator/=(double scalar) {
    log::out("called Vector3 &Vector3::operator/=(double scalar)");
    if (scalar != 0) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }
    throw;
}

Vector3 Vector3::operator-() const {
    log::out("called Vector3 Vector3::operator-() const");
    return Vector3(-x, -y, -z);
}

bool Vector3::operator==(const Vector3 &other) const {
    log::out("called bool Vector3::operator==(const Vector3 &other) const");
    return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator!=(const Vector3 &other) const {
    log::out("called bool Vector3::operator!=(const Vector3 &other) const");
    return !(*this == other);
}

double Vector3::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector3 Vector3::normalize() const {
    double mag = magnitude();
    if (mag != 0) {
        return Vector3(x / mag, y / mag, z / mag);
    }
    throw;
}

double Vector3::dot(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}

std::ostream &operator<<(std::ostream &os, const Vector3 &vec) {
    os << "(x:" << vec.x << ", y:" << vec.y << ", z:" << vec.z << ")";
    return os;
}

} // namespace core
