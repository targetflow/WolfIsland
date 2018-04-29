//
// Created by katya on 20/04/18.
//

#ifndef CPP_WOLF_W_H
#define CPP_WOLF_W_H
#include "Wolf.h"

class Wolf_W: public Wolf{
private:
    int chosenMoveDirection;
    float health;
public:
    Wolf_W();
    ~Wolf_W();
    float gethealth();
    void sethealth(int _health);
    int chooseMoveDirectionforWolf_W(std::vector<int> listOfAvailableSteps, int cellNumber);
    void TryToEatOrDie();
    int getChosenMoveDirection();
    void setChosenMoveDirection(int direction);
    void TryToMakeOffspring();
protected:
};
#endif //CPP_WOLF_W_H
