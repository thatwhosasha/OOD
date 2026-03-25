#pragma once

#include <memory>
#include "Circle.h"

using namespace std;

class CircleCreator 
{
public:
	static CircleCreator& getInstance();
	unique_ptr<IShape> CreateShape(int x, int y, float radius) const;

private:
	CircleCreator() = default;
	~CircleCreator() = default;
	CircleCreator(const CircleCreator&) = delete;
	CircleCreator& operator = (const CircleCreator&) = delete; 
};