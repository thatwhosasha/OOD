#pragma once
#include "IShape.h" 
#include <SFML/Graphics.hpp>
#include <memory>

class IShapeVisitor;

class Rectangle : public IShape
{
private:
    sf::RectangleShape rectangle;
    float width, height;
    float x, y;  // Координаты левого верхнего угла

public:
    Rectangle(int x1, int y1, int x2, int y2);
    Rectangle(float x, float y, float width, float height);

    void draw(sf::RenderWindow& window) const override;
    float calculateArea() const override;
    float calculatePerimeter() const override;
    void accept(IShapeVisitor& visitor) const override;
    std::unique_ptr<IShape> clone() const override;

    // Геттеры
    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }
};