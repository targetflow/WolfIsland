//
// Created by katya on 20/04/18.
//

#ifndef CPP_WOLF_W_H
#define CPP_WOLF_W_H
class Wolf_W: public Animal{
private:
public:
    float health;
    void move();
    void TryToEatOrDie();
    void TryToMakeOffspring();

protected:

};
#endif //CPP_WOLF_W_H
