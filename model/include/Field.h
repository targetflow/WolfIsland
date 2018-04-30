//
// Created by katya on 20/04/18.
//

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
