#include "Game.h"
int main(int argc, char* argv[]) {
	Game game;
	if (game.Init()) {
		game.GameLoop();
	}
	game.ShutDown();

	return 0;
}