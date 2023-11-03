#include <iostream>
#include "SFML/Graphics.hpp"
#include "Transform3D.h"
#include "Vector4.h"
#include "Cube.h"





std::ostream& operator<<(std::ostream& out, const Vector4f& vec)
{
	return out << vec.x << ' ' << vec.y << ' ' << vec.z << ' ' << vec.w;
}


int main()
{

	Cube cube;

	cube[0] = sf::Vector3f(-1, -1, -1);
	cube[1] = sf::Vector3f(-1, -1, 1);
	cube[2] = sf::Vector3f(-1, 1, 1);
	cube[3] = sf::Vector3f(-1, 1, -1);

	cube[4] = sf::Vector3f(1, -1, -1);
	cube[5] = sf::Vector3f(1, -1, 1);
	cube[6] = sf::Vector3f(1, 1, 1);
	cube[7] = sf::Vector3f(1, 1, -1);

	cube.scale(40, 40, 40);



	/*Vector4f v4(5, -2, 7, 1);

	Transform3D scale;

	scale.scale(2, -2, -2);

	std::cout << v4 * scale << '\n';*/


	/*Transform3D m1, m2;

	m1[0] = 15;
	m1[1] = 98;
	m1[2] = 2;
	m1[3] = -42;
	m1[4] = -5;
	m1[5] = 0;
	m1[6] = 32;
	m1[7] = 87;
	m1[8] = -2;
	m1[9] = 13;
	m1[10] = 1;
	m1[11] = 76;
	m1[12] = -23;
	m1[13] = 8;
	m1[14] = -15;
	m1[15] = 24;

	m2[0] = -14;
	m2[1] = 0;
	m2[2] = 33;
	m2[3] = 12;
	m2[4] = -78;
	m2[5] = 74;
	m2[6] = 3;
	m2[7] = 45;
	m2[8] = 5;
	m2[9] = 16;
	m2[10] = 17;
	m2[11] = -22;
	m2[12] = 89;
	m2[13] = 61;
	m2[14] = 0;
	m2[15] = 37;

	v4 * m1;*/


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
			
		}

		main_window.clear();

		if (clock.getElapsedTime().asMilliseconds() > 50)
		{
			cube.rotate_z(5);
			cube.rotate_y(5);
			//cube.translate(-2, -20, -20);
			clock.restart();
		}

		main_window.draw(cube);

		main_window.display();

	}

	

}


