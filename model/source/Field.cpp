//
// Created by katya on 20/04/18.
//

#include "../include/Field.h"
#include <random>
#include <iostream>

Field::Field()
{
    for(int i = 0; i < 400; i++)
    {
        std::vector <int> acquiredCoordinates;
        acquiredCoordinates.emplace_back((i/20)+1);
        acquiredCoordinates.emplace_back((i%20)+1);
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
        int index = uni(rng);
        cells[index].getRabbits().emplace_back(Rabbit());
        std::cout << "Rabbit added to: [" << cells[index].getCoordinates()[0] << ", " << cells[index].getCoordinates()[1] << "]." << std::endl;
    }

    std::cout << "Field initialized" << std::endl;
}