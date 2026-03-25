#include "Triangle.h"

using namespace std;

class TriangleCreator
{
public:
	static TriangleCreator& getInstance();
	unique_ptr<IShape> CreateShape(int x1, int y1, int x2, int y2, int x3, int y3) const; 

private:
	TriangleCreator() = default;
	~TriangleCreator() = default;
	TriangleCreator(const TriangleCreator&) = delete;
	TriangleCreator& operator = (const TriangleCreator&) = delete;
};