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

#include "../include/Field.h"

Field::Field()
{
    for(int i = 0; i < 400; i++)
    {
        std::vector <int> acquiredCoordinates;
        // calculates actual cell coordinates
        acquiredCoordinates.emplace_back((i/20) + 1);
        acquiredCoordinates.emplace_back((i%20) + 1);
        // add to every cell in vector of cells coordinates that correspond to the placement on the field
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
