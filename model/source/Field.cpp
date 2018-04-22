//
// Created by katya on 20/04/18.
//

#include "../include/Field.h"

Field::Field()
{
    for(int i = 1; i <= 400; i++)
    {
        std::vector <int> acquiredCoordinates;
        acquiredCoordinates.emplace_back(i);
        acquiredCoordinates.emplace_back((i/20)+1);
        cells.emplace_back(Cell(acquiredCoordinates));
    }

}

Field::~Field()
{
    cells.clear();
}

std::vector<Cell> Field::getCells()
{
    return cells;
}