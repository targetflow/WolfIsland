//
// Created by katya on 20/04/18.
//

#ifndef CPP_RABBIT_H
#define CPP_RABBIT_H
#include "Animal.h"
#include <vector>

class Rabbit: public Animal{
private:
    int chosenMoveDirection;
public:
    Rabbit();
    ~Rabbit();
    int chooseMoveDirection(std::vector<int> listOfAvailableSteps);
    int getChosenMoveDirection();
    void setChosenMoveDirection(int direction);
    void spread();
protected:
};
#endif //CPP_RABBIT_H
