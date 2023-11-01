#pragma once
#include "SFML/Graphics.hpp"
#include "Vector4.h"
#include <iostream>



class Transform3D
{

private:

	float matrix[16]{};


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

	

};



Transform3D operator*(const Transform3D& left, const Transform3D& right);


Vector4f operator*(const Vector4f& left, const Transform3D& right);
