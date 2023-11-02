#pragma once
#include "SFML/Graphics.hpp"
#include "Vector4.h"
#include <iostream>

#define PI 3.14159265359f



class Transform3D
{

private:

	float matrix[16]{ 1,0,0,0,  0,1,0,0,  0,0,1,0,  0,0,0,1 };


public:

	float& operator[](uint16_t index)
	{

		if(index > 15)
		{
			throw std::out_of_range("Index for matrix was > 15");
		}

		return matrix[index];

	}

	float operator[](uint16_t index) const
	{

		if (index > 15)
		{
			throw std::out_of_range("Index for matrix was > 15");
		}

		return matrix[index];

	}

	

	void rotate_x(float angle);
	void rotate_y(float angle);
	void rotate_z(float angle);

	void translate(float x, float y, float z);
	void translate(const sf::Vector3f& offset);

};



Transform3D operator*(const Transform3D& left, const Transform3D& right);


Vector4f operator*(const Vector4f& left, const Transform3D& right);
