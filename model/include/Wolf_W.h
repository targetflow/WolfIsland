//
// Created by katya on 20/04/18.
//

#ifndef CPP_WOLF_W_H
#define CPP_WOLF_W_H
#include "Wolf.h"

class Wolf_W: public Wolf{
private:
    float health;
public:
    int chooseMoveDirection(std::vector<int> listOfAvailableSteps);
    void TryToEatOrDie();
    void TryToMakeOffspring();
protected:
};
#endif //CPP_WOLF_W_H
