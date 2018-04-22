//
// Created by katya on 20/04/18.
//

#ifndef CPP_RABBIT_H
#define CPP_RABBIT_H
#include "Animal.h"

class Rabbit: public Animal{
private:
    float health;
public:
    Rabbit();
    ~Rabbit();
    void move();
    void spread();
protected:
};
#endif //CPP_RABBIT_H
