#pragma once
#include <cstdint>
#include <vector>
#include "Quad.h"
#include "Cell.h"
class QuadTree
{
public:
	QuadTree(std::vector<Cell> aliveCells);
	int64_t max;
	int64_t min;
	Quad* root;
};

