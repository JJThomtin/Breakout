#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <chrono>
class Game
{
public:
	bool Init();
	void GameLoop();
	void ShutDown();
private:

	void HandleEvents();

	void Update();

	void Draw();

	bool isRunning = true;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};

