#include "Rectangle.h"
#include "IShapeVisitor.h"
#include <cmath>

using namespace std;

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
    : x(static_cast<float>(min(x1, x2))),
    y(static_cast<float>(min(y1, y2))),
    width(static_cast<float>(abs(x2 - x1))),
    height(static_cast<float>(abs(y2 - y1)))
{
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setPosition(this->x, this->y);
    rectangle.setFillColor(sf::Color::Green);
}

Rectangle::Rectangle(float x, float y, float width, float height)
    : x(x), y(y), width(width), height(height)
{
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
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

void Rectangle::accept(IShapeVisitor& visitor) const
{
    visitor.visit(*this);
}

unique_ptr<IShape> Rectangle::clone() const
{
    return make_unique<Rectangle>(x, y, width, height);
}