#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>

#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#include "CircleCreator.h"
#include "RectangleCreator.h"
#include "TriangleCreator.h"

using namespace std;

void parseShapesFromFile(const string& filename,
    vector<unique_ptr<IShape>>& circles,
    vector<unique_ptr<IShape>>& rectangles,
    vector<unique_ptr<IShape>>& triangles,
    vector<unique_ptr<IShape>>& shapes);

void printShapeInfo(const vector<unique_ptr<IShape>>& shapes, const string& shapeName, const string& fileName);

void renderShapes(sf::RenderWindow& window, vector<unique_ptr<IShape>>& shapes);