//
// Created by katya on 20/04/18.
//

#include "../include/Field.h"

Field::Field()
{
    for(int i = 1; i <= 400; i++)
    {
        cells.emplace_back(Cell());
    }
}

Field::~Field()
{
    cells.clear();
}

std::vector <Cell> Field::getCells()
{
    return cells;
}