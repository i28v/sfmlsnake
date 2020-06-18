#include "Food.hpp"

Food::Food()
{
    sprite = new Sprite();
    texture = new Texture();
    texture->loadFromFile("assets/food.png");
    sprite->setTexture(*texture);
    sprite->setScale(2.0f, 2.0f);
    sprite->setPosition(32.0f * (float)(rand() % 20), 32.0f * (float)(rand() % 20));
}

Food::~Food()
{
    delete sprite;
    delete texture;
}

void Food::drawTo(RenderWindow& window)
{
    window.draw(*sprite);
}

void Food::update(Snake& snake, int& score)
{
    if(snake.getSnakeHeadRect().intersects(sprite->getGlobalBounds()))
    {
        sprite->setPosition(32.0f * (float)(rand() % 20), 32.0f * (float)(rand() % 20));
        snake.snakeLength++;
        score++;
    }
}
