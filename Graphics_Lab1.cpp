#include <iostream>
#include "SFML/Graphics.hpp"






void check_bounds(const sf::RectangleShape& rect, sf::Vector2f& direction, const sf::RenderWindow& window)
{

	float pos_x = rect.getPosition().x;
	float pos_y = rect.getPosition().y;

	if ((pos_x + rect.getSize().x / 2) > window.getSize().x || (pos_x - rect.getSize().x / 2) < 0)
	{
		direction.x = -direction.x;
	}
	if ((pos_y + rect.getSize().y / 2) > window.getSize().y || (pos_y - rect.getSize().y / 2) < 0)
	{
		direction.y = -direction.y;
	}

}



int main()
{

	sf::RenderWindow main_window(sf::VideoMode(1200, 800), "Graphics window");



	sf::RectangleShape rectangle(sf::Vector2f(200, 100));
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(sf::Vector2f(200, 150));

	sf::CircleShape circle(100);
	circle.setOrigin(sf::Vector2f(100, 100));
	circle.setFillColor(sf::Color::Magenta);
	circle.setPosition(sf::Vector2f(700, 450));


	sf::Vector2f direction(1, 1);
	sf::Vector2f speed(0.25, 0.25);


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

		check_bounds(rectangle, direction, main_window);


		sf::Vector2f offset(direction.x * speed.x, direction.y * speed.y);

		rectangle.move(offset);



		main_window.clear(sf::Color::Yellow);

		main_window.draw(circle);
		main_window.draw(rectangle);

		main_window.display();

	}



}


