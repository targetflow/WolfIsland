//
// Created by katya on 20/04/18.
//

#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H
class Animal{
public:
    virtual void move()=0;
protected:
    float health;
};
#endif //CPP_ANIMAL_H
