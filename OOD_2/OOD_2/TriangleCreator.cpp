#include <memory>
#include "TriangleCreator.h"

using namespace std;

TriangleCreator& TriangleCreator::getInstance()
{
	static TriangleCreator instance;
	return instance;
}

unique_ptr<IShape> TriangleCreator::CreateShape(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return make_unique<Triangle>(x1, y1, x2, y2, x3, y3);
}
