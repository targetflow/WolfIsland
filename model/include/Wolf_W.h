//
// Created by katya on 20/04/18.
//

#ifndef CPP_WOLF_W_H
#define CPP_WOLF_W_H
#include "Wolf.h"
#include "../../utils/utils.h"

class Wolf_W: public Wolf{
private:
    int chosenMoveDirection;
    float health;
public:
    Wolf_W();
    ~Wolf_W();
    float getHealth();
    void setHealth(float _health);
    int chooseMoveDirection(std::vector<int> listOfAvailableSteps);
    int getChosenMoveDirection();
    void setChosenMoveDirection(int direction);
protected:
};
#endif //CPP_WOLF_W_H
