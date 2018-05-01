//
// Created by katya on 20/04/18.
//

#ifndef CPP_WOLF_M_H
#define CPP_WOLF_M_H
#include "Wolf.h"
#include "../../utils/utils.h"

class Wolf_M: public Wolf{
private:
    float health;
    int chosenMoveDirection;
public:
    Wolf_M();
    ~Wolf_M();
    float getHealth();
    void setHealth(float _health);
    int chooseMoveDirection(std::vector<int> listOfAvailableSteps);
    int getChosenMoveDirection();
    void setChosenMoveDirection(int direction);
    void TryToMakeOffspring();
protected:
};
#endif //CPP_WOLF_M_H
