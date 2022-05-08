#pragma once

#include <string>
#include <vector>
#include "Point.h"

class InputState {
public:
	static void GetAliveCellsFromFile(std::string aString, std::vector<Point>& points);
};