#pragma once

#include "InputState.h"
#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>

constexpr int TICK = 100;

int main(int argc, char* argv[])
{
    std::cout << "Game of Life Riot Games Edition!\n";
    
    InputState::GetAliveCellsFromFile("input.txt", Game::GetInstance().GetAliveCellList());

    int i = 0;
    while (i < TICK)
    {
        Game::GetInstance().FillActiveBoard();
        Game::GetInstance().PrintGeneration();
        Game::GetInstance().RenderGeneration();
        //test to see if render is rendering each square.
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        system("pause");
        Game::GetInstance().GetNextGeneration();
        i++;
    }
    
    return 0;
}


