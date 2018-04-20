//
// Created by katya on 20/04/18.
//

#ifndef CPP_CELL_H
#define CPP_CELL_H
#include "Wolf_W.h"
#include "Wolf_M.h"
#include "Rabbit.h"
class Cell{
public:
    int coordinates[2];
    Wolf_M wolf_m[];
    Wolf_W wolf_w[];
    Rabbit rabbit[];
    int fence[7];

private:
protected:
};
#endif //CPP_CELL_H
