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

Vector2::Vector2(double x, double y) :
        x(x), y(y) {}

// Vector addition
Vector2 Vector2::operator+(const Vector2 &other) const {
    return Vector2(x + other.x, y + other.y);
}

// Scalar addition (not very common, but keeping as per your interface)
Vector2 Vector2::operator+(double &other) const {
    return Vector2(x + other, y + other);
}

// Vector subtraction
Vector2 Vector2::operator-(const Vector2 &other) const {
    return Vector2(x - other.x, y - other.y);
}

// Component-wise vector multiplication
Vector2 Vector2::operator*(const Vector2 &other) const {
    return Vector2(x * other.x, y * other.y);
}

// Scalar multiplication
Vector2 Vector2::operator*(double scalar) const {
    return Vector2(x * scalar, y * scalar);
}

// Scalar division
Vector2 Vector2::operator/(double scalar) const {
    return Vector2(x / scalar, y / scalar);
}

// Vector addition assignment
Vector2 &Vector2::operator+=(const Vector2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}

// Vector subtraction assignment
Vector2 &Vector2::operator-=(const Vector2 &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

// Scalar multiplication assignment
Vector2 &Vector2::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

// Scalar division assignment
Vector2 &Vector2::operator/=(double scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

// Negation (unary minus)
Vector2 Vector2::operator-() const {
    return Vector2(-x, -y);
}

// Equality check
bool Vector2::operator==(const Vector2 &other) const {
    return x == other.x && y == other.y;
}

// Inequality check
bool Vector2::operator!=(const Vector2 &other) const {
    return !(*this == other);
}

// Magnitude of the vector
double Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

// Normalize the vector (return a unit vector)
Vector2 Vector2::normalize() const {
    double mag = magnitude();
    if (mag == 0) {
        return Vector2(0, 0); // Avoid division by zero
    }
    return *this / mag;
}

// Dot product
double Vector2::dot(const Vector2 &other) const {
    return x * other.x + y * other.y;
}

// Overload stream insertion operator for printing
std::ostream &operator<<(std::ostream &os, const Vector2 &vec) {
    os << "Vector2(" << vec.x << ", " << vec.y << ")";
    return os;
}

} // namespace core
