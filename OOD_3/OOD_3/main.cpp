#include "ShapeDecorator.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ofstream output("output.txt", ios::trunc);
    output.close();

    vector<unique_ptr<IShape>> circles;
    vector<unique_ptr<IShape>> rectangles;
    vector<unique_ptr<IShape>> triangles;
    vector<unique_ptr<IShape>> shapes;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Geometric Shapes");

    parseShapesFromFile("input.txt", circles, rectangles, triangles, shapes);

    ofstream outFile("output.txt", ios::app);
    if (!outFile.is_open())
    {
        cerr << "Error: Cannot open output.txt" << endl;
        return 1;
    }

    int circleCount = 1;
    for (const auto& shape : circles)
    {
        float area = shape->calculateArea();
        float perimeter = shape->calculatePerimeter();
        string outputStr = "CIRCLE_" + to_string(circleCount) +
            ": P=" + to_string(static_cast<int>(perimeter)) +
            "; S=" + to_string(static_cast<int>(area));
        cout << outputStr << endl;
        outFile << outputStr << endl;
        ++circleCount;
    }

    int rectCount = 1;
    for (const auto& shape : rectangles)
    {
        float area = shape->calculateArea();
        float perimeter = shape->calculatePerimeter();
        string outputStr = "RECTANGLE_" + to_string(rectCount) +
            ": P=" + to_string(static_cast<int>(perimeter)) +
            "; S=" + to_string(static_cast<int>(area));
        cout << outputStr << endl;
        outFile << outputStr << endl;
        ++rectCount;
    }

    int triangleCount = 1;
    for (const auto& shape : triangles)
    {
        float area = shape->calculateArea();
        float perimeter = shape->calculatePerimeter();
        string outputStr = "TRIANGLE_" + to_string(triangleCount) +
            ": P=" + to_string(static_cast<int>(perimeter)) +
            "; S=" + to_string(static_cast<int>(area));
        cout << outputStr << endl;
        outFile << outputStr << endl;
        ++triangleCount;
    }
    outFile.close();

    renderShapes(window, shapes);

    return 0;
}