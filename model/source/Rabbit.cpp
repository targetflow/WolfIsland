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

#include "../include/Rabbit.h"

Rabbit::Rabbit()
{
    // chosenMoveDirection will be -1 by default, because -1 cell doesn't exist. Count begin from 0.
    chosenMoveDirection = -1;
}

Rabbit::~Rabbit() = default;

int Rabbit::chooseMoveDirection(std::vector<int> listOfAvailableSteps){
    std::cout << "Yo! I`m a rabbit. Available steps for me are: ";
    for (int &i: listOfAvailableSteps)
        std::cout << i << ' ';
    // randomly get the cell from ListOfAvailableSteps (list, which contain cell coordinates,
    // where rabbit can potentially go) and set this value to chosenMoveDirection variable.
    chosenMoveDirection = listOfAvailableSteps.at(random_number(0, listOfAvailableSteps.size()-1));
    std::cout << ". I chose go to: " << chosenMoveDirection << std::endl;
    return chosenMoveDirection;
}

int Rabbit::getChosenMoveDirection()
{
    return chosenMoveDirection;
}

void Rabbit::setChosenMoveDirection(int direction)
{
    chosenMoveDirection = direction;
}
