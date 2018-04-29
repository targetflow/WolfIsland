//
// Created by katya on 20/04/18.
//

#include "../include/Cell.h"

Cell::Cell(std::vector <int> acquiredCoordinates)
{
    for(int i = 0; i < 2; i++)
    {
        coordinates.emplace_back(acquiredCoordinates[i]); //pass actual coords here
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

std::vector<Rabbit> * Cell::getRabbits()
{
    return &rabbits;
}

std::vector<Wolf_W> * Cell::getWolf_W(){
    return & wolf_w;
}