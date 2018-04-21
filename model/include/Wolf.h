//
// Created by katya on 20/04/18.
//

#ifndef CPP_WOLF_H
#define CPP_WOLF_H
#include "Animal.h"
class Wolf: public Animal{
private:
    float health;
public:
    virtual void move()=0;
    virtual void TryToEatOrDie()=0;
protected:
};
#endif //CPP_WOLF_H
