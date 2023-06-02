#pragma once

#include "Game.h"
class Paddle
{
public:
	Paddle();
	void PaddleUpdate();
	void PaddleSetDir(int d);
	SDL_FRect* PaddleGetRect();

	float getPaddleXPos() {
		return paddleXPos;
	}

	float getPaddleYPos() {
		return paddleYPos;
	}
private:
	int paddleDirection = 0;
	int paddleWidth = 20;
	int paddleHeight = 100;
	float paddleXPos;
	float paddleYPos;
	float paddleSpeed;

	SDL_FRect paddleShape;
};

