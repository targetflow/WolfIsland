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

#ifndef CPP_CELL_H
#define CPP_CELL_H

#include <vector>

#include "Wolf_W.h"
#include "Wolf_M.h"
#include "Rabbit.h"

// Cell - a class that describes the contents of each cell(400) in field(20x20), its coordinates
// and animals that live on each of them
class Cell{
private:
    // contains valid cell coordinates
    std::vector <int> coordinates;
    // contains rabbit-objects who now live in current cell
    std::vector <Rabbit> rabbits;
    // contains female wolf-objects who now live in current cell
    std::vector <Wolf_W> wolf_w;
    // contains male wolf-objects who now live in current cell
    std::vector <Wolf_M> wolf_m;
    // indicates the presence of the fence in current cell
    bool _isFence;

public:
    Cell(std::vector <int> acquiredCoordinates);
    ~Cell();

    void setFence(bool isFence);
    bool isFence();

    std::vector <Rabbit>* getRabbits();
    std::vector <Wolf_W>* getWolf_W();
    std::vector <Wolf_M>* getWolf_M();
protected:
};
#endif //CPP_CELL_H
