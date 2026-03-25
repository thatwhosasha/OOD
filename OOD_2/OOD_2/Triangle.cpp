#include "Triangle.h"
#include <cmath>

using namespace std;

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	: p1(x1, y1), p2(x2, y2), p3(x3, y3)
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
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
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