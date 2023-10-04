#include <iostream>
#include <math.h>
#include "SFML/Graphics.hpp"



int main() {
    // Создаем окно SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Static and Dynamic Objects");

    window.setVerticalSyncEnabled(true);

    // Создаем статический круг
    sf::CircleShape staticCircle(50); // радиус 50 пикселей
    staticCircle.setFillColor(sf::Color::Blue);
    staticCircle.setPosition(100, 100); // позиция на экране

    // Создаем динамический треугольник
    sf::CircleShape dynamicTriangle(30, 3); // стороны 30 пикселей
    dynamicTriangle.setFillColor(sf::Color::Red);
    dynamicTriangle.setPosition(50, 50); // позиция на экране
    dynamicTriangle.setOrigin(25, 25);  //центр треугольника


    // Создаем статическую звездочку
    sf::ConvexShape star;
    star.setPointCount(8); // устанавливаем ей 8 вершин

    // Устанавливаем координаты вершин
    star.setPoint(0, sf::Vector2f(500, 100));
    star.setPoint(1, sf::Vector2f(525, 175));
    star.setPoint(2, sf::Vector2f(600, 200));
    star.setPoint(3, sf::Vector2f(525, 225));
    star.setPoint(4, sf::Vector2f(500, 300));
    star.setPoint(5, sf::Vector2f(475, 225));
    star.setPoint(6, sf::Vector2f(400, 200));
    star.setPoint(7, sf::Vector2f(475, 175));
    

    star.setFillColor(sf::Color::Yellow); 
    star.setOutlineThickness(8); // устанавливаем толщину контура звездочки
    star.setOutlineColor(sf::Color::Blue); // устанавливаем цвет контура


    int a = 1;
    float x, y;

    while (window.isOpen()) 
    {

        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        //Смкщкние координат треугольника
        x = 300 + round(100 * cos(a * 3.14 / 180));
        y = 400 + round(100 * sin(a * 3.14 / 180)) * -1;
        
        a+=2;

        dynamicTriangle.setPosition(x, y);


        //Очищаем и выводим
        window.clear();
        window.draw(staticCircle);
        window.draw(star);
        window.draw(dynamicTriangle);
        window.display();
    }

    return 0;
}



