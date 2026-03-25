#include "ShapeDecorator.h"

int main()
{
    std::ofstream output("output.txt", std::ios::trunc);
    output.close();

    std::vector<std::unique_ptr<IShape>> circles;
    std::vector<std::unique_ptr<IShape>> rectangles;
    std::vector<std::unique_ptr<IShape>> triangles;
    std::vector<std::unique_ptr<IShape>> shapes;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualizer");

    parseShapesFromFile("input.txt", circles, rectangles, triangles, shapes);

    printShapeInfo(circles, "CIRCLE", "output.txt");
    printShapeInfo(rectangles, "RECTANGLE", "output.txt");
    printShapeInfo(triangles, "TRIANGLE", "output.txt");

    renderShapes(window, shapes);

    return 0;
}