//
// Created by katya on 20/04/18.
//

#include "../include/Cell.h"

Cell::Cell()
{
    for(int i = 1; i <= 2; i++)
    {
        coordinates.emplace_back(); //pass actual coords here
    }
}

Cell::~Cell()
{
    coordinates.clear();
    rabbits.clear();
}

std::vector <int> Cell::getCoordinates()
{
    return coordinates;
}

std::vector <Rabbit> Cell::getRabbits()
{
    return rabbits;
}
