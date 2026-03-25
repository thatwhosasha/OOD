#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class IShapeVisitor;

class IShape
{
public:
    virtual ~IShape() = default;

    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual float calculateArea() const = 0;
    virtual float calculatePerimeter() const = 0;
    virtual void accept(IShapeVisitor& visitor) const = 0;
    virtual std::unique_ptr<IShape> clone() const = 0;
};