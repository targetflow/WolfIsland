//
// Created by katya on 20/04/18.
//

#include "../include/Field.h"
#include <random>
#include <iostream>

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

void Field::initialize(int nRabbits)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(0, 399); // guaranteed unbiased

    for(int i = 0; i < nRabbits; i++)
    {
        cells[uni(rng)].getRabbits().emplace_back(Rabbit());
    }

    std::cout << "Field initialized" << std::endl;
}