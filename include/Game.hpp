#ifndef GAME_HPP
#define GAME_HPP

#include "deps.hpp"
#include "Snake.hpp"
#include "Food.hpp"
class Game
{
public:
	Game();
	virtual ~Game();
	void init();
	void mainLoop();
	void cleanUp();
	bool gameOver;
private:
	void events(RenderWindow& window, Event& event);
	void input();
	void update();
	void draw(RenderWindow& window);
	int snakeUpdateDelay;
	int score;
	RenderWindow* gameWindow;
	Event* eventHandler;
	Snake* snake;
	Food* food;
	Texture* backgroundTexture;
	Sprite* backgroundSprite;
	Font* lblFont;
	Text* lblText;
	std::ostringstream scoreString;
};

#endif /* GAME_HPP */
