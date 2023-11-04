#include <iostream>
#include "SFML/Graphics.hpp"
#include "Transform3D.h"
#include "Vector4.h"
#include "Cube.h"
#include <fstream>
#include <vector>

#define OBS_DISTANCE 1000





std::ostream& operator<<(std::ostream& out, const Vector4f& vec)
{
	return out << vec.x << ' ' << vec.y << ' ' << vec.z << ' ' << vec.w;
}

std::istream& operator>>(std::istream& in, sf::Vector2f& vec)
{
	return in >> vec.x >> vec.y;
}





sf::VertexArray create_face(sf::Vector2f* points)
{

	sf::VertexArray face(sf::LineStrip, 4);

	face[0] = points[0];
	face[1] = points[1];
	face[2] = points[2];
	face[3] = points[3];

	//face[0] = points[0];
	//face[1] = points[1];
	//face[2] = points[2];
	//face[3] = points[0];
	//face[4] = points[3];
	//face[5] = points[2];

	return face;

}





int main()
{

	std::ifstream file_input("Coords.txt");
	if(!file_input.is_open())
	{
		throw std::exception("Couldn't open the file");
	}



	float letter_thickness = 1.5, letter_scale = 40, letter_distance = 0;
	std::vector<sf::Vector3f> points;
	Transform3D letter_tr;

	sf::Vector2f temp;
	while(file_input >> temp)
	{
		points.push_back(sf::Vector3f(temp.x * letter_scale, temp.y * letter_scale, letter_distance));
		points.push_back(sf::Vector3f(temp.x * letter_scale, temp.y * letter_scale, letter_distance + letter_thickness * letter_scale));
	}



    sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	sf::Clock clock;



	while (main_window.isOpen())
	{
		
		sf::Event main_event;

		while (main_window.pollEvent(main_event))
		{

			if (main_event.type == sf::Event::Closed)
			{
				main_window.close();
			}

			if (main_event.type == sf::Event::Closed)
			{
				main_window.close();
			}
			
		}





		if (clock.getElapsedTime().asMilliseconds() > 50)
		{
			letter_tr.rotate_y(5);
			clock.restart();
		}



		

		std::vector<sf::Vector2f> projection(points.size());
		for (size_t i = 0; i < projection.size(); i++)
		{
			Vector4f temp = Vector4f(points[i].x, points[i].y, points[i].z, 1) * letter_tr;

			projection[i] = sf::Vector2f(OBS_DISTANCE / (OBS_DISTANCE + temp.z) * temp.x + main_window.getSize().x / 2,
				OBS_DISTANCE / (OBS_DISTANCE + temp.z) * temp.y + main_window.getSize().y / 2);
		}



		main_window.clear();

		sf::Vector2f verticies[4];

		for (size_t i = 0, size = projection.size() - 2; i < size; i+=2)
		{
			verticies[0] = projection[i];
			verticies[1] = projection[i + 2];
			verticies[2] = projection[i + 3];
			verticies[3] = projection[i + 1];

			main_window.draw(create_face(verticies));
		}

		verticies[0] = projection[projection.size()-2];
		verticies[1] = projection[0];
		verticies[2] = projection[1];
		verticies[3] = projection[projection.size() - 1];

		main_window.draw(create_face(verticies));



		for (size_t i = 0, size = projection.size() - 2; i < size; i+=2)
		{

			verticies[0] = projection[i];
			verticies[1] = projection[i + 2];
			verticies[2] = projection[size - 2 - i];
			verticies[3] = projection[size - i];

			main_window.draw(create_face(verticies));



			verticies[0] = projection[i + 1];
			verticies[1] = projection[i + 3];
			verticies[2] = projection[size - 1 - i];
			verticies[3] = projection[size + 1 - i];

			main_window.draw(create_face(verticies));

		}
		




		main_window.display();

	}

	

}


