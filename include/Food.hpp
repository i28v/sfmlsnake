#ifndef FOOD_H
#define FOOD_H

#include "deps.hpp"
#include "Snake.hpp"


class Food
{
    public:
        Food();
        virtual ~Food();
        void drawTo(RenderWindow& window);
        void update(Snake& snake, int& score);

    private:
        Sprite* sprite;
        Texture* texture;
};

#endif // FOOD_H
