#include "WindowRenderer.h"
#include <iostream>
#include <stdexcept>
void WindowRenderer::Render(const std::vector<Point>& alivePositions)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    for (const auto& position : alivePositions)
    {
        //figure out scaling // finding differen grids
        if (position.x > -1 && position.y > -1 && position.x < 100 && position.y < 100)
        {
            rect.x = position.x * CELL_SIZE;
            rect.y = position.y * CELL_SIZE;

            SDL_RenderDrawRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    SDL_SetRenderTarget(renderer, nullptr);
    SDL_RenderPresent(renderer);
}

WindowRenderer::WindowRenderer()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Initaliztion of SDL failed: " << SDL_GetError() << std::endl;
        throw std::runtime_error(SDL_GetError());
    }

    //init window
    window = SDL_CreateWindow("Riot Games Game of Life - Harman Brar", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
        throw std::runtime_error(SDL_GetError());
    }

    //init renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        SDL_DestroyWindow(window);
        std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
        throw std::runtime_error(SDL_GetError());
    }

    rect.w = CELL_SIZE;
    rect.h = CELL_SIZE;
}

WindowRenderer::~WindowRenderer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
