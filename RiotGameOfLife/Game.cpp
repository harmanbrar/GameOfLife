#include "Game.h"
#include "WindowRenderer.h"
#include <iostream>

void Game::FillActiveBoard()
{
    for (const auto& alivePosition : aliveCells)
    {
        //if map has alive position mark position as alive otherwise add it to map.
        auto found = gameBoard.find(alivePosition);
        if (found == gameBoard.end())
        {
            Cell cell;
            cell.neighborCount = 0;
            cell.alive = 1;
            gameBoard[alivePosition] = cell;
        }
        else
        {
            gameBoard[alivePosition].alive = true;
        }
        //for the given alive position add neighbors into map as dead if neighbor already exists increase neighborcount.
        for (const auto& neighborCell : alivePosition.neighbours())
        {
            auto foundNeighbour = gameBoard.find(neighborCell);
            if (foundNeighbour == gameBoard.end())
            {
                Cell cell;
                cell.neighborCount = 1;
                cell.alive = 0;
                gameBoard[neighborCell] = cell;
            }
            else
            {
                gameBoard[neighborCell].neighborCount++;
            }
        }
    }
}

void Game::PrintGeneration()
{
    if (!aliveCells.empty())
    {
        std::cout << "----Generation: " << currentGeneration << "----" << "\n";
        for (const auto& point : aliveCells)
        {
            std::cout << point.x << " " << point.y << "\n";
        }
        std::cout << "----end of generation----" << std::endl;
    }
}

void Game::RenderGeneration()
{
    WindowRenderer::GetInstance().Render(aliveCells);
}

void Game::GetNextGeneration()
{
    currentGeneration++;
    //we erase to preserve realloc
    aliveCells.erase(aliveCells.begin(), aliveCells.end());
    for (auto const& keyValuePair : gameBoard)
    {
        auto cellPosition = keyValuePair.first;
        auto cell = keyValuePair.second;
        /*
        * if the cell isn't under or over populated it remains and is added to alive list
        * else if the cell is dead and has 3 alive neighbors it is added to the alive list
        */
        if ((!((int)cell.neighborCount < 2 || (int)cell.neighborCount > 3)) && (int)cell.alive)
        {
            aliveCells.push_back(cellPosition);
        }
        else if (!(int)cell.alive && (int)cell.neighborCount == 3)
        {
            aliveCells.push_back(cellPosition);
        }
    }
    gameBoard.erase(gameBoard.begin(), gameBoard.end());
}

std::vector<Point>& Game::GetAliveCellList()
{
    return aliveCells;
}
