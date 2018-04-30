//
// Created by katya on 20/04/18.
//

#include "../include/Wolf_W.h"



Wolf_W::Wolf_W()
{
    chosenMoveDirection = -1;
}
Wolf_W::~Wolf_W()
= default;

int Wolf_W :: chooseMoveDirection(std::vector<int> listOfAvailableSteps)
{
    chosenMoveDirection = listOfAvailableSteps.at(random_number(0,listOfAvailableSteps.size()-1));
    return chosenMoveDirection;
}

int Wolf_W :: getChosenMoveDirection()
{
    return chosenMoveDirection;
}

void Wolf_W :: setChosenMoveDirection(int direction)
{
    chosenMoveDirection = direction;
}

void Wolf_W :: TryToEatOrDie()
{

}
void Wolf_W::sethealth(int _health)
{
    health = _health;
}
float Wolf_W::gethealth()
{
    return health;
}