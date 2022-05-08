#pragma once
#include "Cell.h"
#include "Point.h"
#include <stdlib.h>  
class Quad
{
public:
	Quad();
	Quad(Point topL, Point botR);
	void insert(Cell* aNode);
	Cell* search(Point aPosition);
	bool inBounds(Point aPosition);

	Point bottomLeftPoint;
	Point topRightPoint;

	bool isLeaf;
	Cell* data;

	Quad* topLeft;
	Quad* topRight;
	Quad* bottomRight;
	Quad* bottomLeft;
private:
	
};

