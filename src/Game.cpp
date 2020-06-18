#include "Game.hpp"

Game::Game()
{

}

Game::~Game()
{

}

void Game::init()
{
    srand(time(NULL));
	snakeUpdateDelay = 0;
	score = 0;
	gameOver = false;
	gameWindow = new RenderWindow(VideoMode(640, 640), "Snake", Style::Titlebar | Style::Close);
	eventHandler = new Event();
	gameWindow->setFramerateLimit(60);
	backgroundTexture = new Texture();
	backgroundSprite = new Sprite();
	backgroundTexture->loadFromFile("assets/background.png");
	backgroundSprite->setTexture(*backgroundTexture);
	backgroundSprite->setScale(640/128, 640/128);
	snake = new Snake();
	food = new Food();
}

void Game::events(RenderWindow& window, Event& event)
{
	while(window.pollEvent(event))
	{
		if(event.type == Event::Closed)
		{
			gameOver = true;
		}
	}
}

void Game::input()
{
	if(Keyboard::isKeyPressed(Keyboard::Up) && snake->snakeDirection != Down)
	{
		snake->snakeDirection = Up;
	}
    else if(Keyboard::isKeyPressed(Keyboard::Down)&& snake->snakeDirection != Up)
	{
		snake->snakeDirection = Down;
	}
	else if(Keyboard::isKeyPressed(Keyboard::Left)&& snake->snakeDirection != Right)
	{
		snake->snakeDirection = Left;
	}
    else if(Keyboard::isKeyPressed(Keyboard::Right)&& snake->snakeDirection != Left)
	{
		snake->snakeDirection = Right;
	}
}

void Game::update()
{
	snakeUpdateDelay++;
	if(snakeUpdateDelay > 5 )
	{
		snakeUpdateDelay = 0;
    	snake->update(gameOver);
	}
	food->update(*snake, score);
}

void Game::draw(RenderWindow& window)
{
	window.clear();
	window.draw(*backgroundSprite);
	snake->drawTo(window);
	food->drawTo(window);
	window.display();
}

void Game::mainLoop()
{
	events(*gameWindow, *eventHandler);
	input();
	update();
	draw(*gameWindow);
}


void Game::cleanUp()
{
	gameWindow->close();
	delete gameWindow;
	delete eventHandler;
	delete snake;
}
