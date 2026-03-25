#include "Circle.h"

Circle::Circle(int x, int y, float radius) : radius(radius)
{
    circle.setRadius(radius);
    circle.setPosition(x - radius, y - radius); 
    circle.setFillColor(sf::Color::Blue);
}

void Circle::draw(sf::RenderWindow& window) const
{
    window.draw(circle);
}

float Circle::calculateArea() const
{
    return 3.14159f * radius * radius;
}

float Circle::calculatePerimeter() const
{
    return 2 * 3.14159f * radius;
}