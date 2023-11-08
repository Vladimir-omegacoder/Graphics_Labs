#include <iostream>
#include <string>
#include "Letter_G.h"
#include <fstream>
#include "SFML/Graphics.hpp"



int main()
{
	setlocale(LC_ALL, "ru");

    sf::RenderWindow main_window(sf::VideoMode(800, 600), "Lab 2");

	std::string path = "Peaks.txt";
	std::ifstream fin;

	fin.open(path);

	if (!fin.is_open())
	{
		std::cout << "Помилка відкриття файла\n\n";
	}


	Letter_G G;

	fin >> G;

	//G[0] = sf::Vector3f(-0.5, 1.5, 0);
	//G[1] = sf::Vector3f(-0.5, 1.5, 0.5);
	//G[2] = sf::Vector3f(-0.5, -1, 0);
	//G[3] = sf::Vector3f(-0.5, -1, 0.5);
	//G[4] = sf::Vector3f(1, -1, 0);
	//G[5] = sf::Vector3f(1, -1, 0.5);
	//G[6] = sf::Vector3f(1, -1.5, 0);
	//G[7] = sf::Vector3f(1, -1.5, 0.5);
	//G[8] = sf::Vector3f(-1, -1.5, 0);
	//G[9] = sf::Vector3f(-1, -1.5, 0.5);
	//G[10] = sf::Vector3f(-1, 1.5, 0);
	//G[11] = sf::Vector3f(-1, 1.5, 0.5);

	G.scaling(Vector4f(140, 140, 140));
	G.RotY(45);


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

		main_window.draw(G);

		main_window.display();

	}
}


