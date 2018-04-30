//
// Created by katya on 20/04/18.
//

#include "../include/Rabbit.h"

Rabbit::Rabbit()
{
    chosenMoveDirection = -1;
}

Rabbit::~Rabbit() = default;

int Rabbit::chooseMoveDirection(std::vector<int> listOfAvailableSteps){
    std::cout << "Yo! I`m a rabbit. Available steps for me are: ";
    for (int &i: listOfAvailableSteps)
        std::cout << i << ' ';
    //std::cout << "Yo! I`m a rabbit. And I deside to go to: " << listOfAvailableSteps.at(uni(rng)) << std::endl;
    chosenMoveDirection = listOfAvailableSteps.at(random_number(0, listOfAvailableSteps.size()-1));
    std::cout << ". I chose go to: " << chosenMoveDirection << std::endl;
    return chosenMoveDirection;
}

int Rabbit::getChosenMoveDirection()
{
    return chosenMoveDirection;
}

void Rabbit::setChosenMoveDirection(int direction)
{
    chosenMoveDirection = direction;
}

void Rabbit::spread(){

}
