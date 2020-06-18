#include "Game.hpp"

int main()
{
	Game game;
	game.init();
	while(game.gameOver == false)
	{
		game.mainLoop();
	}
	game.cleanUp();
	return 0;
}
