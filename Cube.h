#pragma once
#include "Transform3D.h"
#include "Vector4.h"

#define OBS_DISTANCE 1000
//#define VIEW_POINT sf::Vector3f(400, 300, 1000)


class Cube : public Transform3D, public sf::Drawable
{

private:

	sf::Vector3f vertices[8]{};

	Transform3D::operator[];



	sf::VertexArray create_face(sf::Vector2f* points) const
	{

		sf::VertexArray face(sf::LineStrip, 6);

		face[0] = points[0];
		face[1] = points[1];
		face[2] = points[2];
		face[3] = points[0];
		face[4] = points[3];
		face[5] = points[2];

		return face;

	}


public:

	Cube(){}

	sf::Vector3f& operator[](uint16_t index)
	{

		if (index > 8)
		{
			throw std::out_of_range("Index for matrix was > 15");
		}

		return vertices[index];
	
	}

	sf::Vector3f operator[](uint16_t index) const
	{

		if (index > 8)
		{
			throw std::out_of_range("Index for matrix was > 15");
		}

		return vertices[index];

	}



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{

		sf::Vector2f points[8];
		for (int i = 0; i < 8; i++)
		{

			Vector4f temp = Vector4f(vertices[i].x, vertices[i].y, vertices[i].z, 1) * (static_cast<const Transform3D&>(*this));

			points[i] = sf::Vector2f(OBS_DISTANCE / (OBS_DISTANCE + temp.z) * temp.x + target.getSize().x / 2,
				OBS_DISTANCE / (OBS_DISTANCE + temp.z) * temp.y + target.getSize().y / 2);

		}

		sf::VertexArray face;
		sf::Vector2f face_temp[4];

		face_temp[0] = points[0];
		face_temp[1] = points[1];
		face_temp[2] = points[2];
		face_temp[3] = points[3];

		face = create_face(face_temp);
		target.draw(face, states);


		face_temp[0] = points[4];
		face_temp[1] = points[5];
		face_temp[2] = points[6];
		face_temp[3] = points[7];

		face = create_face(face_temp);
		target.draw(face, states);


		face_temp[0] = points[0];
		face_temp[1] = points[1];
		face_temp[2] = points[5];
		face_temp[3] = points[4];

		face = create_face(face_temp);
		target.draw(face, states);


		face_temp[0] = points[1];
		face_temp[1] = points[2];
		face_temp[2] = points[6];
		face_temp[3] = points[5];

		face = create_face(face_temp);
		target.draw(face, states);


		face_temp[0] = points[2];
		face_temp[1] = points[3];
		face_temp[2] = points[7];
		face_temp[3] = points[6];

		face = create_face(face_temp);
		target.draw(face, states);


		face_temp[0] = points[3];
		face_temp[1] = points[0];
		face_temp[2] = points[4];
		face_temp[3] = points[7];

		face = create_face(face_temp);
		target.draw(face, states);

	}

};

