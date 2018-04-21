//
// Created by katya on 20/04/18.
//

#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H
class Animal{
    Animal();
    virtual ~Animal();
private:
public:
    float health;
     virual void move()=0;
protected:


};
#endif //CPP_ANIMAL_H
