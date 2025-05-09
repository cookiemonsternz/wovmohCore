#ifndef DATATYPES_H
#define DATATYPES_H

#include <variant>

enum class PinDataType {
    INVALID,
    NUMBER,
    BOOLEAN,
    COLOR,
    VECTOR
};

struct ColorData {
    float r = 0.0f, g = 0.0f, b = 0.0f, a = 0.0f;
    bool operator==(const ColorData& other) const {
        return r == other.r && g == other.g && b == other.b && a == other.a;
    }
    // COLORS
    ColorData operator+(const ColorData& other) const { // Color + Color
        return ColorData{ r + other.r, g + other.g, b + other.b, a + other.a };
    }
    ColorData operator-(const ColorData& other) const { // Color - Color
        return ColorData{ r - other.r, g - other.g, b - other.b, a - other.a };
    }
    ColorData operator*(const ColorData& other) const { // Color * Color
        return ColorData{ r * other.r, g * other.g, b * other.b, a * other.a };
    }
    ColorData operator/(const ColorData& other) const { // Color / Color
        return ColorData{ r / other.r, g / other.g, b / other.b, a / other.a };
    }
    // SCALARS
    ColorData operator+(float scalar) const { // Color + Scalar
        return ColorData{ r + scalar, g + scalar, b + scalar, a + scalar };
    }
    ColorData operator-(float scalar) const { // Color - Scalar
        return ColorData{ r - scalar, g - scalar, b - scalar, a - scalar };
    }    
    ColorData operator*(float scalar) const { // Color * Scalar
        return ColorData{ r * scalar, g * scalar, b * scalar, a * scalar };
    }
    ColorData operator/(float scalar) const { // Color / Scalar
        return ColorData{ r / scalar, g / scalar, b / scalar, a / scalar };
    }
      
};

struct VectorData {
    float x = 0.0f, y = 0.0f, z = 0.0f;
    // VECTORS
    bool operator==(const VectorData& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    VectorData operator+(const VectorData& other) const { // Vector + Vector
        return VectorData{ x + other.x, y + other.y, z + other.z };
    }
    VectorData operator-(const VectorData& other) const { // Vector - Vector
        return VectorData{ x - other.x, y - other.y, z - other.z };
    }
    VectorData operator*(const VectorData& other) const { // Vector * Vector
        return VectorData{ x * other.x, y * other.y, z * other.z };
    }
    VectorData operator/(const VectorData& other) const { // Vector / Vector
        return VectorData{ x / other.x, y / other.y, z / other.z };
    }
    // SCALARS
    VectorData operator+(float scalar) const { // Vector + Scalar
        return VectorData{ x + scalar, y + scalar, z + scalar };
    }
    VectorData operator-(float scalar) const { // Vector - Scalar
        return VectorData{ x - scalar, y - scalar, z - scalar };
    }
    VectorData operator*(float scalar) const { // Vector * Scalar
        return VectorData{ x * scalar, y * scalar, z * scalar };
    }
    VectorData operator/(float scalar) const { // Vector / Scalar
        return VectorData{ x / scalar, y / scalar, z / scalar };
    }
};

using DataValue = std::variant<
    std::monostate, // Undefined / invalid
    double, // Number
    bool, // Bool
    ColorData, // Color
    VectorData // Vector
>;

#endif // DATATYPES_H
