#include "ShapePrinter.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

void ShapePrinter::visit(const Circle& circle)
{
    cout << "CIRCLE: P=" << static_cast<int>(circle.calculatePerimeter())
        << "; S=" << static_cast<int>(circle.calculateArea()) << endl;
}

void ShapePrinter::visit(const Rectangle& rectangle)
{
    cout << "RECTANGLE: P=" << static_cast<int>(rectangle.calculatePerimeter())
        << "; S=" << static_cast<int>(rectangle.calculateArea()) << endl;
}

void ShapePrinter::visit(const Triangle& triangle)
{
    cout << "TRIANGLE: P=" << static_cast<int>(triangle.calculatePerimeter())
        << "; S=" << static_cast<int>(triangle.calculateArea()) << endl;
}