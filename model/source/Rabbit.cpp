//
// Created by katya on 20/04/18.
//

#include "../include/Rabbit.h"

Rabbit::Rabbit()
{
//chosenMoveDirection will be -1 by default, because -1 cell doesn't exist. Count begin from 0.
    chosenMoveDirection = -1;
}

Rabbit::~Rabbit() = default;

int Rabbit::chooseMoveDirection(std::vector<int> listOfAvailableSteps){
    std::cout << "Yo! I`m a rabbit. Available steps for me are: ";
    for (int &i: listOfAvailableSteps)
        std::cout << i << ' ';
//randomly get the cell from ListOfAvailableSteps (list, which contain cell coordinates, where rabbit can potentially go) and set this value to
//chosenMoveDirection variable.
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
