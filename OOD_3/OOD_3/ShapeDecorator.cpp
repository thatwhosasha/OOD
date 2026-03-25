#include "ShapeDecorator.h"

using namespace std;

void parseShapesFromFile(const string& filename,
    vector<unique_ptr<IShape>>& circles,
    vector<unique_ptr<IShape>>& rectangles,
    vector<unique_ptr<IShape>>& triangles,
    vector<unique_ptr<IShape>>& shapes)
{
    ifstream input(filename);
    string shape, str, strX, strY, rad;

    if (!input.is_open())
    {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    while (getline(input, str))
    {
        if (str.empty()) continue;

        istringstream line(str);
        getline(line, shape, ':');

        if (shape == "CIRCLE")
        {
            float radius = 0;
            int x = 0, y = 0;
            line.ignore(3);
            getline(line, strX, ',');
            x = stoi(strX);
            getline(line, strY, ';');
            y = stoi(strY);
            line.ignore(3);
            getline(line, rad);
            radius = stof(rad);

            auto& circleCreator = CircleCreator::getInstance();
            auto circle = circleCreator.CreateShape(x, y, radius);

            circles.push_back(circle->clone());
            shapes.push_back(move(circle));
        }
        else if (shape == "RECTANGLE")
        {
            int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            line.ignore(4);
            getline(line, strX, ',');
            x1 = stoi(strX);
            getline(line, strY, ';');
            y1 = stoi(strY);
            line.ignore(4);
            getline(line, strX, ',');
            x2 = stoi(strX);
            getline(line, strY);
            y2 = stoi(strY);

            auto& rectangleCreator = RectangleCreator::getInstance();
            auto rect = rectangleCreator.CreateShape(x1, y1, x2, y2);

            rectangles.push_back(rect->clone());
            shapes.push_back(move(rect));
        }
        else if (shape == "TRIANGLE")
        {
            int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;

            line.ignore(4);
            getline(line, strX, ',');
            x1 = stoi(strX);
            getline(line, strY, ';');
            y1 = stoi(strY);

            line.ignore(4);
            getline(line, strX, ',');
            x2 = stoi(strX);
            getline(line, strY, ';');
            y2 = stoi(strY);

            line.ignore(4);
            getline(line, strX, ',');
            x3 = stoi(strX);
            getline(line, strY);
            y3 = stoi(strY);

            auto& triangleCreator = TriangleCreator::getInstance();
            auto tri = triangleCreator.CreateShape(x1, y1, x2, y2, x3, y3);

            triangles.push_back(tri->clone());
            shapes.push_back(move(tri));
        }
    }
    input.close();
}

void renderShapes(sf::RenderWindow& window, vector<unique_ptr<IShape>>& shapes)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        for (const auto& shape : shapes)
        {
            shape->draw(window);
        }
        window.display();
    }
}