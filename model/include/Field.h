//
// Created by katya on 20/04/18.
//

#ifndef CPP_FIELD_H
#define CPP_FIELD_H
#include "Cell.h"

class Field{
private:
    Cell* cells;
public:
    Field();
    ~Field();
    Cell* getCells();
protected:
};

#endif //CPP_FIELD_H
