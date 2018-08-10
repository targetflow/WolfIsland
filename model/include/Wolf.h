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

#ifndef CPP_WOLF_H
#define CPP_WOLF_H

#include "Animal.h"

// Wolf - abstract base class for every wolf-agent in a model.
class Wolf: public Animal {
public:
    // chooses on which cell from the list of currently available cells
    // on the field to move at the next step
    virtual int chooseMoveDirection(std::vector<int> listOfAvailableSteps) = 0;

protected:
    float health; // contains how much health this agent has now (if < 0 - it dies)
    int chosenMoveDirection = -1; // path (cell numb), which is chosen by the wolf (according to some properties) to go
};
#endif //CPP_WOLF_H
