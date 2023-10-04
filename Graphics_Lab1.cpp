#include <iostream>
#include <math.h>
#include "SFML/Graphics.hpp"



void move_triangle(sf::CircleShape& triangle, int& a, int startx, int starty, int s, int vector)
{
    if (a == 360) a = 0;

    if (vector <= 0) vector = -1;
    else vector = 1;

    float x, y;

    x = startx + round(100 * cos(a * 3.14 / 180));
    y = starty + round(100 * sin(a * 3.14 / 180)) * vector;

    a += s;

    triangle.setPosition(x, y);
}


int main() {
    // Создаем окно SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Static and Dynamic Objects");

    window.setVerticalSyncEnabled(true);

    // Создаем статический круг
    sf::CircleShape staticCircle(50); // радиус 50 пикселей
    staticCircle.setFillColor(sf::Color(240, 128, 128));
    staticCircle.setPosition(100, 100); // позиция на экране



    // Создаем динамический треугольник
    sf::CircleShape dynamicTriangle(30, 3); // стороны 30 пикселей
    dynamicTriangle.setFillColor(sf::Color(219, 112, 147));
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
    

    star.setFillColor(sf::Color(255, 240, 245));
    star.setOutlineThickness(8); // устанавливаем толщину контура звездочки
    star.setOutlineColor(sf::Color(255, 182, 193)); // устанавливаем цвет контура



    int a = 1;

    while (window.isOpen()) 
    {

        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        //Смещение координат треугольника 
        move_triangle(dynamicTriangle, a, 175, 400, 2, -1);

        

        //Очищаем и выводим

        window.clear(sf::Color(255, 250, 240));

        window.draw(staticCircle);
        window.draw(star);
        window.draw(dynamicTriangle);
        window.display();
    }

    return 0;
}
