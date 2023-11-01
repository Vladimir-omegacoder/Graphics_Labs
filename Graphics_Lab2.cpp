#include <iostream>
#include "SFML/Graphics.hpp"
#include "Letter_3d.h"




int main()
{

	int c_letter[4]{ 1, 4, 2, 3 };
	Letter_3d(4, c_letter);

    sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

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

		main_window.display();

	}

	

}


