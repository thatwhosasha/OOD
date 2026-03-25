#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
    : width(std::abs(x2 - x1)), height(std::abs(y2 - y1))
{
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setPosition(x1, y1);
    rectangle.setFillColor(sf::Color::Green);
}

void Rectangle::draw(sf::RenderWindow& window) const
{
    window.draw(rectangle);
}

float Rectangle::calculateArea() const
{
    return width * height;
}

float Rectangle::calculatePerimeter() const
{
    return 2 * width + 2 * height;
}