#pragma once
#include "IShape.h" 

class Rectangle : public IShape
{
private:
    sf::RectangleShape rectangle;
    int width, height;

public:
    Rectangle(int x1, int y1, int x2, int y2);

    void draw(sf::RenderWindow& window) const override;
    float calculateArea() const override;
    float calculatePerimeter() const override;
};
