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
//    Wolf_M wolf_m[];
//    Wolf_W wolf_w[];
//    int fence[8];
public:
    Cell(std::vector <int> acquiredCoordinates);
    ~Cell();
    std::vector <int> getCoordinates();
    std::vector<Rabbit> * getRabbits();
protected:
};
#endif //CPP_CELL_H
