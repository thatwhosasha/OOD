#include "Rectangle.h"

using namespace std;

class RectangleCreator
{
public:
	static RectangleCreator& getInstance();
	unique_ptr<IShape> CreateShape(int x1, int y1, int x2, int y2) const;

private:
	RectangleCreator() = default;
	~RectangleCreator() = default;
	RectangleCreator(const RectangleCreator&) = delete;
	RectangleCreator& operator = (const RectangleCreator&) = delete;
};
