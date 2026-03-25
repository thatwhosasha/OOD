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
    while (getline(input, str))
    {
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
            radius = stoi(rad);

            circles.push_back(make_unique<Circle>(x, y, radius));
            shapes.push_back(make_unique<Circle>(x, y, radius));
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

            rectangles.push_back(make_unique<Rectangle>(x1, y1, x2, y2));
            shapes.push_back(make_unique<Rectangle>(x1, y1, x2, y2));
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

            triangles.push_back(make_unique<Triangle>(x1, y1, x2, y2, x3, y3));
            shapes.push_back(make_unique<Triangle>(x1, y1, x2, y2, x3, y3));
        }
    }
}

void printShapeInfo(const vector<unique_ptr<IShape>>& shapes, const string& shapeName, const string& fileName)
{
    ofstream output(fileName, ios::app);
    int count = 1;
    for (const auto& shape : shapes)
    {
        float area = shape->calculateArea();
        float perimeter = shape->calculatePerimeter();
        cout << shapeName << "_" << count << ": P=" << perimeter << "; S=" << area << endl;
        output << shapeName << "_" << count << ": P=" << perimeter << "; S=" << area << endl;
        ++count;
    }
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

        window.clear();
        for (const auto& shape : shapes)
        {
            shape->draw(window);
        }
        window.display();
    }
}