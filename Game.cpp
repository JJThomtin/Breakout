#include "Game.h"

using Clock = std::chrono::steady_clock;
using namespace std::literals;
auto constexpr dt = 1.0s / 60.;
int constexpr SCREENWIDTH = 400;
int constexpr SCREENHEIGHT = 600;
using duration = std::chrono::duration<double>;
using time_point = std::chrono::time_point<Clock, duration>;

bool  Game::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return false;
	}
	
	int windowWidthInPixels, windowHeightInPixels;
	window = SDL_CreateWindow("BREAKOUT", SCREENWIDTH, SCREENHEIGHT, 0);
	SDL_GetWindowSizeInPixels(window, &windowWidthInPixels, &windowHeightInPixels);
	double scaleX = static_cast<double>(windowWidthInPixels) / SCREENWIDTH;
	double scaleY = static_cast<double>(windowHeightInPixels) / SCREENHEIGHT;
	std::cout << scaleX << " " << scaleY;

	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	if (!window) {
		return false;
	}

	renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	int w, h;
	SDL_GetRenderOutputSize(renderer, &w, &h);
	SDL_SetRenderScale(renderer, scaleX, scaleY);

	if (!renderer) {
		return false;
	}
	

	return true;
}


void Game::GameLoop() {
	//Tick cap at 60 ticks per sec
	time_point t{};
	int i{ 0 };
	time_point currentTime = Clock::now();
	duration accumulator = 0s;
	while (isRunning) {
		time_point newTime = Clock::now();
		auto frameTime = newTime - currentTime;
		if (frameTime > 0.25s)
			frameTime = 0.25s;
		currentTime = newTime;

		accumulator += frameTime;
		while (accumulator >= dt)
		{
			HandleEvents();
			Update();
			Draw();
			t += dt;
			accumulator -= dt;
		}
	}
}



void Game::HandleEvents() {
	SDL_Event event;

	//Exit program via exiting the window or pressing esc
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) {
			isRunning = false;
		}
	}

	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	if (keystates[SDL_SCANCODE_ESCAPE]) {
		isRunning = false;
	}
}

void Game::Update() {

}

void Game::Draw() {

}

void Game::ShutDown() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}