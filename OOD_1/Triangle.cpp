#include "Triangle.h"
#include <cmath>

static float distance(const sf::Vector2f& a, const sf::Vector2f& b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

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

void Triangle::draw(sf::RenderWindow& window) const
{
    window.draw(triangle);
}

float Triangle::calculateArea() const
{
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    float s = (a + b + c) / 2.0f;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

float Triangle::calculatePerimeter() const
{
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    return a + b + c;
}