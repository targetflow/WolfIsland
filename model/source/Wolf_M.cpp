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

#include "../include/Wolf_M.h"

Wolf_M::Wolf_M() {
    // chosenMoveDirection will be -1 by default, because -1 cell doesn't exist. Count begin from 0.
    chosenMoveDirection = -1;
    health = 1;
}

Wolf_M::~Wolf_M() = default;

int Wolf_M::chooseMoveDirection(std::vector<int> listOfAvailableSteps) {
    // randomly get the cell from ListOfAvailableSteps (list, which contain cell coordinates
    // where male wolf can potentially go) and set this value to chosenMoveDirection variable.
    chosenMoveDirection = listOfAvailableSteps.at(random_number(0, listOfAvailableSteps.size()-1));
    return chosenMoveDirection;
}

int Wolf_M::getChosenMoveDirection() {
    return chosenMoveDirection;
}

void Wolf_M::setChosenMoveDirection(int direction) {
    chosenMoveDirection = direction;
}

void Wolf_M::setHealth(float _health) {
    health = _health;
}

float Wolf_M::getHealth() {
    return health;
}