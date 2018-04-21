//
// Created by katya on 20/04/18.
//

#include "../include/Field.h"

Field::Field()
{
    cells = new Cell[400];
    for(int i = 0; i < 400; i++)
    {
        cells[i] = Cell();
    }
}

Field::~Field()
{
    if(cells)
        delete[] cells;
}

Cell* Field::getCells()
{
    return cells;
}