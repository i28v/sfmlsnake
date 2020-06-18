#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "deps.hpp"

enum Direction
{
	Up=0, Down, Left, Right
};

class Snake
{
public:
	Snake();
	virtual ~Snake();
	void drawTo(RenderWindow& window);
	void update(bool& gameOver);
	int snakeLength;
	Direction snakeDirection;
	FloatRect getSnakeHeadRect();
private:
	Texture* snakeHeadUpTexture;
	Texture* snakeHeadDownTexture;
	Texture* snakeHeadLeftTexture;
	Texture* snakeHeadRightTexture;
	Texture* snakeBodyTexture;
	Sprite* snakeBody[256];

};

#endif /* SNAKE_HPP */
