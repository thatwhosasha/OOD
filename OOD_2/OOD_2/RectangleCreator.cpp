#include <memory>
#include "RectangleCreator.h"

using namespace std;

RectangleCreator& RectangleCreator::getInstance()
{
	static RectangleCreator instance;
	return instance;
}

unique_ptr<IShape> RectangleCreator::CreateShape(int x1, int y1, int x2, int y2) const
{
	return make_unique<Rectangle>(x1, y1, x2, y2);
}
