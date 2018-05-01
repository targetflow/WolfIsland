//
// Created by katya on 20/04/18.
//

#ifndef CPP_WOLF_H
#define CPP_WOLF_H
#include "Animal.h"

class Wolf: public Animal{
public:
    virtual int chooseMoveDirection(std::vector<int> listOfAvailableSteps) = 0;
protected:
    float health;
    int chosenMoveDirection = -1;
};
#endif //CPP_WOLF_H
