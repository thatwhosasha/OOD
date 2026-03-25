#include "Circle.h"
#include "IShapeVisitor.h"

using namespace std;

Circle::Circle(int x, int y, float radius)
    : x(static_cast<float>(x)), y(static_cast<float>(y)), radius(radius)
{
    circle.setRadius(radius);
    circle.setPosition(this->x - radius, this->y - radius);
    circle.setFillColor(sf::Color::Blue);
}

Circle::Circle(float x, float y, float radius)
    : x(x), y(y), radius(radius)
{
    circle.setRadius(radius);
    circle.setPosition(this->x - radius, this->y - radius);
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

void Circle::accept(IShapeVisitor& visitor) const
{
    visitor.visit(*this);
}

unique_ptr<IShape> Circle::clone() const
{
    return make_unique<Circle>(x, y, radius);
}