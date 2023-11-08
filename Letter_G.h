#pragma once
#include "Matrix.h"
#include "Vector4.h"



class Letter_G : public Matrix_f, public sf::Drawable
{

private:

	sf::Vector3f peaks[12]{};



	sf::VertexArray plane(sf::Vector2f* point) const
	{

		sf::VertexArray rectangle(sf::LineStrip, 5);

		rectangle[0] = point[0];
		rectangle[1] = point[1];
		rectangle[2] = point[2];
		rectangle[3] = point[3];
		rectangle[4] = point[0];


		return rectangle;

	}

	sf::Vector2f perspective(Vector4f v, sf::RenderTarget& target) const
	{
		return sf::Vector2f(1500 / (1500 + v.z) * v.x + target.getSize().x / 2,
			1500 / (1500 + v.z) * v.y + target.getSize().y / 2);
	}

public:

	Letter_G() {}

	sf::Vector3f& operator[](uint16_t index)
	{

		if (index > 11)
		{
			throw std::out_of_range("Matrix don't have this index");
		}

		return peaks[index];

	}

	sf::Vector3f operator[](uint16_t index) const
	{

		if (index > 11)
		{
			throw std::out_of_range("Matrix don't have this index");
		}

		return peaks[index];

	}



	friend std::istream& operator>> (std::istream& in, Letter_G& letter)
	{
		float z;
		in >> z;

	    for (int i = 0; i < 12; i = i + 2)
		{
			in >> letter.peaks[i].x;
			letter.peaks[i + 1].x = letter.peaks[i].x;

			in.ignore(1);

			in >> letter.peaks[i].y;
			letter.peaks[i + 1].y = letter.peaks[i].y;

			letter.peaks[i].z = 0;
			letter.peaks[i+1].z = z;
		}

		return in;
	}


	void draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{

		sf::Vector2f points[12];

		for (int i = 0; i < 12; i++)
		{

			Vector4f temp = (static_cast<const Matrix_f&>(*this)) * Vector4f(peaks[i].x, peaks[i].y, peaks[i].z, 1);

			points[i] = perspective(temp, target);

		}

		sf::VertexArray rectangle;

		sf::Vector2f rectangle_temp[4];

		rectangle_temp[0] = points[0];
		rectangle_temp[1] = points[1];
		rectangle_temp[2] = points[3];
		rectangle_temp[3] = points[2];

		rectangle = plane(rectangle_temp);
		target.draw(rectangle, states);


		rectangle_temp[0] = points[2];
		rectangle_temp[1] = points[3];
		rectangle_temp[2] = points[5];
		rectangle_temp[3] = points[4];

		rectangle = plane(rectangle_temp);
		target.draw(rectangle, states);


		rectangle_temp[0] = points[4];
		rectangle_temp[1] = points[5];
		rectangle_temp[2] = points[7];
		rectangle_temp[3] = points[6];

		rectangle = plane(rectangle_temp);
		target.draw(rectangle, states);


		rectangle_temp[0] = points[6];
		rectangle_temp[1] = points[7];
		rectangle_temp[2] = points[9];
		rectangle_temp[3] = points[8];

		rectangle = plane(rectangle_temp);
		target.draw(rectangle, states);


		rectangle_temp[0] = points[8];
		rectangle_temp[1] = points[9];
		rectangle_temp[2] = points[3];
		rectangle_temp[3] = points[2];

		rectangle = plane(rectangle_temp);
		target.draw(rectangle, states);


		rectangle_temp[0] = points[8];
		rectangle_temp[1] = points[9];
		rectangle_temp[2] = points[11];
		rectangle_temp[3] = points[10];

		rectangle = plane(rectangle_temp);
		target.draw(rectangle, states);


		rectangle_temp[0] = points[10];
		rectangle_temp[1] = points[11];
		rectangle_temp[2] = points[1];
		rectangle_temp[3] = points[0];

		rectangle = plane(rectangle_temp);
		target.draw(rectangle, states);

	}

};
