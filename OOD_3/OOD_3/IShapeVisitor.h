#pragma once

class Circle;
class Rectangle;
class Triangle;

class IShapeVisitor {
public:
    virtual ~IShapeVisitor() = default;

    virtual void visit(const Circle& circle) = 0;
    virtual void visit(const Rectangle& rectangle) = 0;
    virtual void visit(const Triangle& triangle) = 0;
};