#pragma once
#include <cmath>

#include "cocos2d.h"

const float Pi = 4 * std::atan(1.0f);
const float TwoPi = 2 * Pi;
//
//template <typename T>
//struct Vec2 {
//    Vec2() {}
//    Vec2(T x, T y) : x(x), y(y) {}
//    T Dot(const Vector2& v) const
//    {
//        return x * v.x + y * v.y;
//    }
//    Vec2 operator+(const Vector2& v) const
//    {
//        return Vec2(x + v.x, y + v.y);
//    }
//    Vec2 operator-(const Vector2& v) const
//    {
//        return Vec2(x - v.x, y - v.y);
//    }
//    Vec2 operator/(float s) const
//    {
//        return Vec2(x / s, y / s);
//    }
//    Vec2 operator*(float s) const
//    {
//        return Vec2(x * s, y * s);
//    }
//    void Normalize()
//    {
//        float s = 1.0f / Length();
//        x *= s;
//        y *= s;
//    }
//    Vec2 Normalized() const 
//    {
//        Vec2 v = *this;
//        v.Normalize();
//        return v;
//    }
//    T LengthSquared() const
//    {
//        return x * x + y * y;
//    }
//    T Length() const
//    {
//        return sqrt(LengthSquared());
//    }
//    operator Vector2<float>() const
//    {
//        return Vector2<float>(x, y);
//    }
//    bool operator==(const Vector2& v) const
//    {
//        return x == v.x && y == v.y;
//    }
//    Vec2 Lerp(float t, const Vector2& v) const
//    {
//        return Vec2(x * (1 - t) + v.x * t,
//                       y * (1 - t) + v.y * t);
//    }
//    template <typename P>
//    P* Write(P* pData)
//    {
//        Vector2* pVector = (Vec2*) pData;
//        *pVector++ = *this;
//        return (P*) pVector;
//    }
//    T x;
//    T y;
//};
//
//template <typename T>
//struct Vec3 {
//    Vec3() {}
//    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
//    void Normalize()
//    {
//        float s = 1.0f / std::sqrt(x * x + y * y + z * z);
//        x *= s;
//        y *= s;
//        z *= s;
//    }
//    Vec3 Normalized() const 
//    {
//        Vec3 v = *this;
//        v.Normalize();
//        return v;
//    }
//    Vec3 Cross(const Vector3& v) const
//    {
//        return Vec3(y * v.z - z * v.y,
//                       z * v.x - x * v.z,
//                       x * v.y - y * v.x);
//    }
//    T Dot(const Vector3& v) const
//    {
//        return x * v.x + y * v.y + z * v.z;
//    }
//    Vec3 operator+(const Vector3& v) const
//    {
//        return Vec3(x + v.x, y + v.y,  z + v.z);
//    }
//    void operator+=(const Vector3& v)
//    {
//        x += v.x;
//        y += v.y;
//        z += v.z;
//    }
//    void operator-=(const Vector3& v)
//    {
//        x -= v.x;
//        y -= v.y;
//        z -= v.z;
//    }
//    void operator/=(T s)
//    {
//        x /= s;
//        y /= s;
//        z /= s;
//    }
//    Vec3 operator-(const Vector3& v) const
//    {
//        return Vec3(x - v.x, y - v.y,  z - v.z);
//    }
//    Vec3 operator-() const
//    {
//        return Vec3(-x, -y, -z);
//    }
//    Vec3 operator*(T s) const
//    {
//        return Vec3(x * s, y * s, z * s);
//    }
//    Vec3 operator/(T s) const
//    {
//        return Vec3(x / s, y / s, z / s);
//    }
//    bool operator==(const Vector3& v) const
//    {
//        return x == v.x && y == v.y && z == v.z;
//    }
//    Vec3 Lerp(float t, const Vector3& v) const
//    {
//        return Vec3(x * (1 - t) + v.x * t,
//                       y * (1 - t) + v.y * t,
//                       z * (1 - t) + v.z * t);
//    }
//    const T* Pointer() const
//    {
//        return &x;
//    }
//    template <typename P>
//    P* Write(P* pData)
//    {
//        Vector3<T>* pVector = (Vec3<T>*) pData;
//        *pVector++ = *this;
//        return (P*) pVector;
//    }
//    T x;
//    T y;
//    T z;
//};
//
//template <typename T>
//struct Vector4 {
//    Vector4() {}
//    Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
//    T Dot(const Vector4& v) const
//    {
//        return x * v.x + y * v.y + z * v.z + w * v.w;
//    }
//    Vector4 Lerp(float t, const Vector4& v) const
//    {
//        return Vector4(x * (1 - t) + v.x * t,
//                       y * (1 - t) + v.y * t,
//                       z * (1 - t) + v.z * t,
//                       w * (1 - t) + v.w * t);
//    }
//    const T* Pointer() const
//    {
//        return &x;
//    }
//    T x;
//    T y;
//    T z;
//    T w;
//};
//
//typedef Vector2<bool> bvec2;
//
//typedef Vector2<int> ivec2;
//typedef Vector3<int> ivec3;
//typedef Vector4<int> ivec4;
//
typedef cocos2d::Vec2 vec2;
typedef cocos2d::Vec3 vec3;
typedef cocos2d::Vec4 vec4;
