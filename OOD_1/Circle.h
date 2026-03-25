#pragma once
#include "IShape.h"

class Circle : public IShape
{
private:
    sf::CircleShape circle;
    float radius;

public:
    Circle(int x, int y, float radius);

    void draw(sf::RenderWindow& window) const override;
    float calculateArea() const override;
    float calculatePerimeter() const override;
};