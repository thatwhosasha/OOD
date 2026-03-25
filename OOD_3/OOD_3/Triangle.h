#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>
#include <memory>

class IShapeVisitor;

class Triangle : public IShape
{
private:
    sf::ConvexShape triangle;
    sf::Vector2f p1, p2, p3;

public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    Triangle(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3);

    void draw(sf::RenderWindow& window) const override;
    float calculateArea() const override;
    float calculatePerimeter() const override;
    void accept(IShapeVisitor& visitor) const override;
    std::unique_ptr<IShape> clone() const override;

    void getPoints(sf::Vector2f& p1, sf::Vector2f& p2, sf::Vector2f& p3) const;
};