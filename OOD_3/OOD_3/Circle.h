#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>
#include <memory>

class IShapeVisitor;

class Circle : public IShape
{
private:
    sf::CircleShape circle;
    float radius;
    float x, y;

public:
    Circle(int x, int y, float radius);
    Circle(float x, float y, float radius);

    void draw(sf::RenderWindow& window) const override;
    float calculateArea() const override;
    float calculatePerimeter() const override;
    void accept(IShapeVisitor& visitor) const override;
    std::unique_ptr<IShape> clone() const override;

    float getX() const { return x; }
    float getY() const { return y; }
    float getRadius() const { return radius; }
};