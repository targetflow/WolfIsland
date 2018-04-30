//
// Created by katya on 20/04/18.
//

#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H
#include <vector>

class Animal{
public:
    virtual int chooseMoveDirection(std::vector<int> listOfAvailableSteps) = 0;
protected:
    float health;
};
#endif //CPP_ANIMAL_H
