#include <iostream>
#include <string>
#include "Letter_G.h"
#include <fstream>
#include "SFML/Graphics.hpp"




int main()
{

    sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	std::string path = "Peaks.txt";
	std::ifstream fin;

	fin.open(path);

	if (!fin.is_open())
	{
		std::cout << "Помилка відкриття файла\n\n";
	}


	Letter_G G;

	fin >> G;

	G.scaling(Vector4f(140, 140, 140));


	//Маштабування
	//////////////////////////////////////////
	 
	//G.scaling(Vector4f(100, 100, 100));


	//G.scaling_X(3);

	//G.scaling_Y(2);

	//G.scaling_Z(10);
	 
    //////////////////////////////////////////



	//G.RotY(45);

	//G.RotX(45);

	//G.RotZ(45);


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

		if (clock.getElapsedTime().asMilliseconds() > 50)
		{
			G.RotX(5);
			clock.restart();
		}


		main_window.clear();

		main_window.draw(G);

		main_window.display();

	}

	

}


