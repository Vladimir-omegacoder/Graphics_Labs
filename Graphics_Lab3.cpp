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

	return face;

}



enum Transform_binds
{

	NONE = -1,

	ROTATE = sf::Keyboard::R,
	SCALE = sf::Keyboard::S,
	TRANSLATE = sf::Keyboard::T,

	TRANSFORM_X = sf::Keyboard::X,
	TRANSFORM_Y = sf::Keyboard::Y,
	TRANSFORM_Z = sf::Keyboard::Z,

};



int main()
{

	sf::Font info_font;
	bool font_available = info_font.loadFromFile("calibri.ttf");
	if (!font_available)
	{
		std::cerr << "Unable to load the font\n";
	}
	
	

	std::ifstream file_input("Coords.txt");
	if(!file_input.is_open())
	{
		throw std::exception("Couldn't open the file");
	}

	

	float letter_thickness = 1.5, letter_scale = 40, letter_distance = 0;

	std::vector<sf::Vector3f> points;

	Transform3D local_tr, global_tr; // Local and global transform
	Transform3D local_scale;
	local_tr.scale(letter_scale, letter_scale, letter_scale);

	sf::Vector2f temp;
	while(file_input >> temp)
	{
		points.push_back(sf::Vector3f(temp.x, temp.y, letter_distance - letter_thickness / 2));
		points.push_back(sf::Vector3f(temp.x, temp.y, letter_distance + letter_thickness / 2));
	}





    sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	sf::Clock clock;

	Transform_binds transform_type = NONE;

	// Transform from input
	sf::Vector3f rotation;
	sf::Vector3f scaling(1, 1, 1);
	sf::Vector3f translation(0, 0, 0);

	while (main_window.isOpen())
	{
		
		sf::Event main_event;



		while (main_window.pollEvent(main_event))
		{

			if (main_event.type == sf::Event::Closed)
			{
				main_window.close();
			}

			if (main_event.type == sf::Event::KeyPressed)
			{
				
				sf::Keyboard::Key pressed_key = main_event.key.code;

				switch (pressed_key)
				{

				case ROTATE:
					transform_type = ROTATE;
					break;

				case SCALE:
					transform_type = SCALE;
					break;

				case TRANSLATE:
					transform_type = TRANSLATE;
					break;

				}

			}

			if(main_event.type == sf::Event::MouseWheelScrolled)
			{

				bool all_transform = true;
				float k_rotation = 8, k_scaling = 0.1, k_translating = 8;

				switch (transform_type)
				{

				case ROTATE:

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_X)))
					{
						rotation.x = (k_rotation * main_event.mouseWheelScroll.delta);
						all_transform = false;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_Y)))
					{
						rotation.y = (k_rotation * main_event.mouseWheelScroll.delta);
						all_transform = false;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_Z)))
					{
						rotation.z = (k_rotation * main_event.mouseWheelScroll.delta);
						all_transform = false;
					}
					if (all_transform)
					{
						rotation.x = rotation.y = rotation.z = (k_rotation * main_event.mouseWheelScroll.delta);
					}

					break;



				case SCALE:

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_X)))
					{
						scaling.x += (k_scaling * main_event.mouseWheelScroll.delta);
						all_transform = false;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_Y)))
					{
						scaling.y += (k_scaling * main_event.mouseWheelScroll.delta);
						all_transform = false;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_Z)))
					{
						scaling.z += (k_scaling * main_event.mouseWheelScroll.delta);
						all_transform = false;
					}
					if (all_transform)
					{
						scaling.x = scaling.y = scaling.z += (k_scaling * main_event.mouseWheelScroll.delta);
					}

					break;



				case TRANSLATE:

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_X)))
					{
						translation.x = (k_translating * main_event.mouseWheelScroll.delta);
						all_transform = false;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_Y)))
					{
						translation.y = (-k_translating * main_event.mouseWheelScroll.delta);
						all_transform = false;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_Z)))
					{
						translation.z = (k_translating * main_event.mouseWheelScroll.delta);
						all_transform = false;
					}
					if (all_transform)
					{
						translation.x = translation.y = translation.z += (k_translating * main_event.mouseWheelScroll.delta);
					}

					break;

				}

			}
			
		}





		// Applying input values transform

		if (clock.getElapsedTime().asMilliseconds() > 50)
		{

			local_tr.rotate_x(rotation.x);
			local_tr.rotate_y(rotation.y);
			local_tr.rotate_z(rotation.z);

			local_scale.scale(scaling);

			global_tr.translate(translation);

			rotation.x = rotation.y = rotation.z = 0;
			scaling.x = scaling.y = scaling.z = 1;
			translation.x = translation.y = translation.z = 0;

			clock.restart();

		}



		

		// Projection coordiantes

		std::vector<sf::Vector2f> projection(points.size());
		for (size_t i = 0; i < projection.size(); i++)
		{
			Vector4f temp = Vector4f(points[i].x, points[i].y, points[i].z, 1) * local_scale * local_tr * global_tr;

			projection[i] = sf::Vector2f(OBS_DISTANCE / (OBS_DISTANCE + temp.z) * temp.x + main_window.getSize().x / 2,
				OBS_DISTANCE / (OBS_DISTANCE + temp.z) * temp.y + main_window.getSize().y / 2);
		}



		// Rendering

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





		if (font_available) {

			sf::String transform_info, axis_info = "Axis: ";

			switch (transform_type)
			{

			case ROTATE:
				transform_info = "Transform type: R \n";
				break;

			case SCALE:
				transform_info = "Transform type: S \n";
				break;

			case TRANSLATE:
				transform_info = "Transform type: T \n";
				break;

			}

			bool all_transform = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_X)))
			{
				axis_info += 'X';
				all_transform = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_Y)))
			{
				axis_info += 'Y';
				all_transform = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(TRANSFORM_Z)))
			{
				axis_info += 'Z';
				all_transform = false;
			}
			if (all_transform)
			{
				axis_info += "XYZ";
			}

			sf::Text info_text(transform_info + axis_info, info_font, 20);

			info_text.setPosition(20, 20);

			main_window.draw(info_text);

		}





		main_window.display();

	}

	

}


