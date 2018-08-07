/**
 * WolfIsland environment modeling project.
 *
 * Copyright 2018 by Kateryna Pereverzeva <katya.pereverzeva2109@gmail.com>
 * Copyright 2018 by Oleksandr Orlovskyi <orlovskyi.alex@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 =========================================================================== */

#include "../include/Cell.h"

//inserts cell coordinates and set default _isFence value.
Cell::Cell(std::vector<int> acquiredCoordinates)
{
    for(int i = 0; i < 2; i++)
    {
        coordinates.emplace_back(acquiredCoordinates[i]); //pass actual coordinates here.
    }

    _isFence = false;
}

//clean Cell and every Cell property.
Cell::~Cell()
{
    coordinates.clear();
    rabbits.clear();
    wolf_w.clear();
    wolf_m.clear();

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