#include "Triangle.h"
#include "IShapeVisitor.h"
#include <cmath>

using namespace std;

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : p1(static_cast<float>(x1), static_cast<float>(y1)),
    p2(static_cast<float>(x2), static_cast<float>(y2)),
    p3(static_cast<float>(x3), static_cast<float>(y3))
{
    triangle.setPointCount(3);
    triangle.setPoint(0, p1);
    triangle.setPoint(1, p2);
    triangle.setPoint(2, p3);
    triangle.setFillColor(sf::Color::Red);
}

Triangle::Triangle(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3)
    : p1(p1), p2(p2), p3(p3)
{
    triangle.setPointCount(3);
    triangle.setPoint(0, p1);
    triangle.setPoint(1, p2);
    triangle.setPoint(2, p3);
    triangle.setFillColor(sf::Color::Red);
}

void Triangle::draw(sf::RenderWindow& window) const
{
    window.draw(triangle);
}

float distance(const sf::Vector2f& p1, const sf::Vector2f& p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

float Triangle::calculateArea() const
{
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    float s = (a + b + c) / 2.0f;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

float Triangle::calculatePerimeter() const
{
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    return a + b + c;
}

void Triangle::accept(IShapeVisitor& visitor) const
{
    visitor.visit(*this);
}

unique_ptr<IShape> Triangle::clone() const
{
    return make_unique<Triangle>(p1, p2, p3);
}

void Triangle::getPoints(sf::Vector2f& p1, sf::Vector2f& p2, sf::Vector2f& p3) const
{
    p1 = this->p1;
    p2 = this->p2;
    p3 = this->p3;
}