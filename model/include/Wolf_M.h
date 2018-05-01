//
// Created by katya on 20/04/18.
//

#ifndef CPP_WOLF_M_H
#define CPP_WOLF_M_H
#include "Wolf.h"

class Wolf_M: public Wolf{
private:
    float health;
public:
    int chooseMoveDirection(std::vector<int> listOfAvailableSteps);
    void TryToMakeOffspring();
protected:
};
#endif //CPP_WOLF_M_H
