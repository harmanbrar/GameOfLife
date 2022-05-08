#pragma once
#include "Point.h"
#include "Cell.h"
#include<vector>
#include<unordered_map>
//#include<map>
//singleton game class only need one for simulation.

struct hashFunction
{
	std::size_t operator() (const Point& point) const
	{
		std::size_t	lhs = std::hash<int64_t>()(point.x);
		std::size_t	rhs = std::hash<int64_t>()(point.y);

		return lhs ^ rhs;
	}
};

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
	std::unordered_map<Point, Cell, hashFunction> gameBoard;
};

