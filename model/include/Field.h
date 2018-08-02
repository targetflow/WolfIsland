//
// Created by katya on 20/04/18.
//
// This file contains information about Field and cells that belong to it.
#ifndef CPP_FIELD_H
#define CPP_FIELD_H
#include "Cell.h"
#include "Rabbit.h"
#include <vector>

class Field{
private:
    std::vector<Cell> cells;
public:
    Field();
    ~Field();
    std::vector<Cell>* getCells();
protected:
};

#endif //CPP_FIELD_H
