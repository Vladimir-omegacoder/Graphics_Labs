#pragma once
#include "SFML/Graphics.hpp"




template <typename T>
struct Vector4
{

	T x;
	T y;
	T z;
	T w;

	Vector4() {}

	Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

};



template <typename T>
Vector4<T> operator+(const Vector4<T>& vector)
{
	return Vector4<T>(vector);
}

template <typename T>
Vector4<T> operator-(const Vector4<T>& vector)
{
	return Vector4<T>(-vector.x, -vector.y, -vector.z, -vector.w);
}



template <typename T>
Vector4<T> operator+(const Vector4<T>& left, const Vector4<T>& right)
{
	return Vector4<T>(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
}

template <typename T>
Vector4<T> operator-(const Vector4<T>& left, const Vector4<T>& right)
{
	return Vector4<T>(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
}



template <typename T>
Vector4<T>& operator+=(Vector4<T>& left, const Vector4<T>& right)
{
	left.x += right.x;
	left.y += right.y;
	left.z += right.z;
	left.w += right.w;

	return left;
}

template <typename T>
Vector4<T>& operator-=(Vector4<T>& left, const Vector4<T>& right)
{
	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;
	left.w -= right.w;

	return left;
}



template <typename T>
Vector4<T> operator*(const T& left, const Vector4<T>& right)
{
	return Vector4<T>(left * right.x, left * right.y, left * right.z, left * right.w);
}

template <typename T>
Vector4<T> operator*(const Vector4<T>& left, const T& right)
{
	return Vector4<T>(left.x * right, left.y * right, left.z * right, left.w * right);
}



template <typename T>
Vector4<T>& operator*=(Vector4<T>& left, const T& right)
{
	left.x *= right;
	left.y *= right;
	left.z *= right;
	left.w *= right;

	return left;
}



template <typename T>
Vector4<T> operator/(const Vector4<T>& left, const T& right)
{
	return Vector4<T>(left.x / right, left.y / right, left.z / right, left.w / right);
}



template <typename T>
Vector4<T>& operator/=(Vector4<T>& left, const T& right)
{
	left.x /= right;
	left.y /= right;
	left.z /= right;
	left.w /= right;

	return left;
}



template <typename T>
bool operator==(const Vector4<T>& left, const Vector4<T>& right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w);
}

template <typename T>
bool operator!=(const Vector4<T>& left, const Vector4<T>& right)
{
	return (left.x != right.x || left.y != right.y || left.z != right.z || left.w != right.w);
}




template struct Vector4<int>;
template struct Vector4<float>;

using Vector4i = Vector4<int>;
using Vector4f = Vector4<float>;