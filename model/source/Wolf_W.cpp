//
// Created by katya on 20/04/18.
//

#include "../include/Wolf_W.h"

Wolf_W::Wolf_W() {
//chosenMoveDirection will be -1 by default, because -1 cell doesn't exist. Count begin from 0.
    chosenMoveDirection = -1;
    health = 1;
}

Wolf_W::~Wolf_W() = default;

int Wolf_W::chooseMoveDirection(std::vector<int> listOfAvailableSteps) {
//randomly get the cell from ListOfAvailableSteps (list, which contain cell coordinates, where female wolf can potentially go) and set this value to
//chosenMoveDirection variable.
    chosenMoveDirection = listOfAvailableSteps.at(random_number(0, listOfAvailableSteps.size()-1));
    return chosenMoveDirection;
}

int Wolf_W::getChosenMoveDirection() {
    return chosenMoveDirection;
}

void Wolf_W::setChosenMoveDirection(int direction) {
    chosenMoveDirection = direction;
}

void Wolf_W::setHealth(float _health) {
    health = _health;
}

float Wolf_W::getHealth() {
    return health;
}