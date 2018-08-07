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

#ifndef SFML_TEST_MAP_H
#define SFML_TEST_MAP_H

#include <SFML/Graphics.hpp>

const int HEIGHT_MAP = 28;
const int WIDTH_MAP = 28;

//0 - field
//1 - menu
const sf::String TileMap[HEIGHT_MAP] = {
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
        "0000000000000000000011111111",
};

#endif //SFML_TEST_MAP_H
