#include <iostream>
#include <fstream>
#include <sstream>
#include "InputState.h"

void InputState::GetAliveCellsFromFile(std::string aString, std::vector<Point>& aliveCells)
{
	std::string line;
	std::ifstream input;
	input.open("input.txt");
	if (input.is_open())
	{
		while (getline(input, line))
		{
			std::stringstream ss(line);
			int i = 0;
			int64_t x = 0;
			int64_t y = 0;
			while (ss.good())
			{
				std::string substr;
				getline(ss, substr, ',');
				if (i == 0)
				{
					// pull out the x location here
					x = stoll(substr);
				}
				else if (i == 1)
				{
					// pull out the y location here
					y = stoll(substr);
				}
				++i;
			}
			aliveCells.push_back(Point(x, y));
		}
		input.close();
	}
}

