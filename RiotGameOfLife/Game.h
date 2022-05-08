#pragma once
#include "Point.h"
#include "Cell.h"
#include<vector>
#include<unordered_map>
#include<map>
//singleton game class only need one for simulation.
class Game
{
public:

	Game(const Game&) = delete;
	static Game& GetInstance()
	{
		static Game instance;
		return instance;
	}

	void FillActiveBoard();
	void PrintGeneration();
	void RenderGeneration();
	void GetNextGeneration();
	std::vector<Point>& GetAliveCellList();
	
private:
	Game()
		: currentGeneration(0)
	{
		aliveCells.reserve(INT16_MAX);
	}
	int64_t currentGeneration;
	std::vector<Point> aliveCells;
	std::map<Point, Cell> gameBoard;
	std::map<Point, Cell> swapBoard;
};

