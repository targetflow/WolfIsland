//
// Created by katya on 20/04/18.
//

#include "../include/Cell.h"

Cell::Cell(std::vector<int> acquiredCoordinates)
{
    for(int i = 0; i < 2; i++)
    {
        coordinates.emplace_back(acquiredCoordinates[i]); //pass actual coords here
    }
    _isFence = false;
}

Cell::~Cell()
{
    coordinates.clear();
    rabbits.clear();
}

void Cell::setFence(bool isFence) {
    _isFence = isFence;
}

bool Cell::isFence() {
    return _isFence;
}

std::vector<Rabbit>* Cell::getRabbits() {
    return &rabbits;
}

std::vector<Wolf_W>* Cell::getWolf_W() {
    return &wolf_w;
}

std::vector<Wolf_M>* Cell::getWolf_M() {
    return &wolf_m;
}