#pragma once
#include "IShape.h"

class Triangle : public IShape
{
private:
    sf::ConvexShape triangle;
    sf::Vector2f p1, p2, p3;
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

    void draw(sf::RenderWindow& window) const override;
    float calculateArea() const override;
    float calculatePerimeter() const override;
};