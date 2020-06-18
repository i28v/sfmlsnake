#include "Snake.hpp"

Snake::Snake()
{
    snakeDirection = Right;
    snakeLength = 8;
    snakeHeadUpTexture = new Texture();
    snakeHeadDownTexture = new Texture();
    snakeHeadLeftTexture = new Texture();
    snakeHeadRightTexture = new Texture();
    snakeBodyTexture = new Texture();
    snakeHeadUpTexture->loadFromFile("assets/snakeheadup.png");
    snakeHeadDownTexture->loadFromFile("assets/snakeheaddown.png");
    snakeHeadLeftTexture->loadFromFile("assets/snakeheadleft.png");
    snakeHeadRightTexture->loadFromFile("assets/snakeheadright.png");
    snakeBodyTexture->loadFromFile("assets/snakebody.png");
    snakeBody[0] = new Sprite();
    snakeBody[0]->setTexture(*snakeHeadRightTexture);
    snakeBody[0]->setScale(2.0f, 2.0f);
    snakeBody[0]->setPosition(256.0f, 32.0f);
    for(int i = 1; i < snakeLength; i++)
    {
        snakeBody[i] = new Sprite();
        snakeBody[i]->setTexture(*snakeBodyTexture);
        snakeBody[i]->setScale(2.0f, 2.0f);
        snakeBody[i]->setPosition(snakeBody[0]->getPosition().x - (float)(32 * i), 32.0f);
    }
    for(int i = snakeLength; i < 255; i++)
    {
        snakeBody[i] = new Sprite();
	snakeBody[i]->setTexture(*snakeBodyTexture);
        snakeBody[i]->setScale(2.0f, 2.0f);
    }
}

Snake::~Snake()
{
    delete snakeHeadUpTexture;
    delete snakeHeadDownTexture;
    delete snakeHeadLeftTexture;
    delete snakeHeadRightTexture;
    delete snakeBodyTexture;
    for(int i = 0; i < 255; i++)
    {
        delete snakeBody[i];
    }
}

void Snake::drawTo(RenderWindow& window)
{
    for(int i = 0; i < snakeLength; i++)
    {
        window.draw(*snakeBody[i]);
    }
}

void Snake::update(bool& gameOver)
{
    for(int i = snakeLength; i > 0; i--)
    {
        snakeBody[i]->setPosition(snakeBody[i-1]->getPosition());
    }
    switch(snakeDirection)
    {
        case Up:
            snakeBody[0]->move(0.0f, -32.0f);
            snakeBody[0]->setTexture(*snakeHeadUpTexture);
	    break;
	case Down:
            snakeBody[0]->move(0.0f, 32.0f);
	    snakeBody[0]->setTexture(*snakeHeadDownTexture);
	    break;
	case Left:
	    snakeBody[0]->move(-32.0f, 0.0f);
	    snakeBody[0]->setTexture(*snakeHeadLeftTexture);
	    break;
        case Right:
            snakeBody[0]->move(32.0f, 0.0f);
	    snakeBody[0]->setTexture(*snakeHeadRightTexture);
	    break;
       	default:
       	    break;
    }

    for(int i = 1; i < snakeLength; i++)
    {
          if(snakeBody[0]->getPosition() == snakeBody[i]->getPosition())
	  {
	      gameOver = true;
	  }
    }    
    
    if(snakeBody[0]->getPosition().x < 0)
    {
        snakeBody[0]->setPosition(640.0f, snakeBody[0]->getPosition().y);
    }
    if(snakeBody[0]->getPosition().x > 640.0f)
    {
        snakeBody[0]->setPosition(0.0f, snakeBody[0]->getPosition().y);
    }
    if(snakeBody[0]->getPosition().y < 0)
    {
        snakeBody[0]->setPosition(snakeBody[0]->getPosition().x, 640.0f);
    }
    if(snakeBody[0]->getPosition().y > 640)
    {
        snakeBody[0]->setPosition(snakeBody[0]->getPosition().x, 0.0f);
    }
}

FloatRect Snake::getSnakeHeadRect()
{
    return snakeBody[0]->getGlobalBounds();
}
