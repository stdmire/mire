#include "vector.h"

namespace core {

Vector3::Vector3(double x, double y, double z) :
        x(x), y(y), z(z) {}

// Vector addition
Vector3 Vector3::operator+(const Vector3 &other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

// Scalar addition (not very common, but keeping as per your interface)
Vector3 Vector3::operator+(double &other) const {
    return Vector3(x + other, y + other, z + other);
}

// Vector subtraction
Vector3 Vector3::operator-(const Vector3 &other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

// Component-wise vector multiplication
Vector3 Vector3::operator*(const Vector3 &other) const {
    return Vector3(x * other.x, y * other.y, z * other.z);
}

// Scalar multiplication
Vector3 Vector3::operator*(double scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

// Scalar division
Vector3 Vector3::operator/(double scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

// Vector addition assignment
Vector3 &Vector3::operator+=(const Vector3 &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

// Vector subtraction assignment
Vector3 &Vector3::operator-=(const Vector3 &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

// Scalar multiplication assignment
Vector3 &Vector3::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

// Scalar division assignment
Vector3 &Vector3::operator/=(double scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

// Negation (unary minus)
Vector3 Vector3::operator-() const {
    return Vector3(-x, -y, -z);
}

// Equality check
bool Vector3::operator==(const Vector3 &other) const {
    return x == other.x && y == other.y && z == other.z;
}

// Inequality check
bool Vector3::operator!=(const Vector3 &other) const {
    return !(*this == other);
}

// Magnitude of the vector
double Vector3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Normalize the vector (return a unit vector)
Vector3 Vector3::normalize() const {
    double mag = magnitude();
    if (mag == 0) {
        return Vector3(0, 0, 0); // Avoid division by zero
    }
    return *this / mag;
}

// Dot product
double Vector3::dot(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Overload stream insertion operator for printing
std::ostream &operator<<(std::ostream &os, const Vector3 &vec) {
    os << "Vector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}

} // namespace core
