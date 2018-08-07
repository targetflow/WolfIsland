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

#ifndef CPP_WOLF_W_H
#define CPP_WOLF_W_H

#include "Wolf.h"
#include "../../utils/utils.h"

class Wolf_W: public Wolf{
private:
    int chosenMoveDirection;
    float health;
public:
    Wolf_W();
    ~Wolf_W();
    float getHealth();
    void setHealth(float _health);
    int chooseMoveDirection(std::vector<int> listOfAvailableSteps);
    int getChosenMoveDirection();
    void setChosenMoveDirection(int direction);
protected:
};
#endif //CPP_WOLF_W_H
