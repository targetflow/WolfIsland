//
// Created by katya on 20/04/18.
//

#include "../include/Wolf_M.h"

Wolf_M::Wolf_M() {
//chosenMoveDirection will be -1 by default, because -1 cell doesn't exist. Count begin from 0.
    chosenMoveDirection = -1;
    health = 1;
}

Wolf_M::~Wolf_M() = default;

int Wolf_M::chooseMoveDirection(std::vector<int> listOfAvailableSteps) {
//randomly get the cell from ListOfAvailableSteps (list, which contain cell coordinates, where male wolf can potentially go) and set this value to
//chosenMoveDirection variable.
    chosenMoveDirection = listOfAvailableSteps.at(random_number(0, listOfAvailableSteps.size()-1));
    return chosenMoveDirection;
}

int Wolf_M::getChosenMoveDirection() {
    return chosenMoveDirection;
}

void Wolf_M::setChosenMoveDirection(int direction) {
    chosenMoveDirection = direction;
}

void Wolf_M::setHealth(float _health) {
    health = _health;
}

float Wolf_M::getHealth() {
    return health;
}
void Wolf_M::TryToMakeOffspring() {

}
