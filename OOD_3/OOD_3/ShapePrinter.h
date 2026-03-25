#pragma once
#include "IShapeVisitor.h"
#include <iostream>

class ShapePrinter : public IShapeVisitor 
{
public:
    void visit(const Circle& circle) override;
    void visit(const Rectangle& rectangle) override;
    void visit(const Triangle& triangle) override;
};