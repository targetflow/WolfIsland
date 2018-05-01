//
// Created by katya on 20/04/18.
//

#ifndef CPP_CELL_H
#define CPP_CELL_H
#include "Wolf_W.h"
#include "Wolf_M.h"
#include "Rabbit.h"
#include <vector>

class Cell{
private:
    std::vector <int> coordinates;
    std::vector <Rabbit> rabbits;
    std::vector <Wolf_W> wolf_w;
    std::vector <Wolf_M> wolf_m;
    bool _isFence;

public:
    Cell(std::vector <int> acquiredCoordinates);
    ~Cell();

    void setFence(bool isFence);
    bool isFence();

    std::vector <Rabbit>* getRabbits();
    std::vector <Wolf_W>* getWolf_W();
    std::vector <Wolf_M>* getWolf_M();
protected:
};
#endif //CPP_CELL_H
