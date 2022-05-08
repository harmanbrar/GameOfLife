#include "QuadTree.h"

QuadTree::QuadTree(std::vector<Cell> aliveCells)
	:min(0), max(0)
{
	root = new Quad(Point(0, UINT64_MAX), Point(UINT64_MAX, 0));
	for(auto& cell : aliveCells)
	{
		Cell* newNode = new Cell(cell);
		root->insert(newNode);
	}
}