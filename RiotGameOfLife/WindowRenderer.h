#pragma once
#include<SDL.h>
#include "Point.h"
#include <vector>
//magic numbers
constexpr int WIDTH = 1000;
constexpr int HEIGHT = 1000;
constexpr int CELL_SIZE = 10;

class WindowRenderer
{
public:
	WindowRenderer(const WindowRenderer&) = delete;
	static WindowRenderer& GetInstance()
	{
		static WindowRenderer instance;
		return instance;
	}
	void Render(const std::vector<Point>& alivePositions);

private:
	WindowRenderer();
	~WindowRenderer();
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect rect;
};

