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

	Vector4(T x, T y, T z, T w = 1) : x(x), y(y), z(z), w(w) {}

};


template struct Vector4<float>;

using Vector4f = Vector4<float>;