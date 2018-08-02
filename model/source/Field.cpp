//
// Created by katya on 20/04/18.
//

#include "../include/Field.h"

//initializes field and sets coordinates for all cells
Field::Field()
{
//iterate through all cells and calculate actual cell coordinates
    for(int i = 0; i < 400; i++)
    {
        std::vector <int> acquiredCoordinates;
        acquiredCoordinates.emplace_back((i/20) + 1);
        acquiredCoordinates.emplace_back((i%20) + 1);
//add to every cell in vector of cells coordinates that correspond to the placement on the field
        cells.emplace_back(Cell(acquiredCoordinates));
    }
}

Field::~Field()
{
    cells.clear();
}

std::vector<Cell>* Field::getCells()
{
    return &cells;
}
