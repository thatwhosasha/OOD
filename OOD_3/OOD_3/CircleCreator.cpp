#include <memory>
#include "CircleCreator.h"

using namespace std;

CircleCreator& CircleCreator::getInstance()
{
	static CircleCreator instance;
	return instance;
}

unique_ptr<IShape> CircleCreator::CreateShape(int x, int y, float radius) const
{
	return make_unique<Circle>(x, y, radius);
}


