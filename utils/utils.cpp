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

#include "utils.h"

int random_number(int begin, int end){
    // creates generator that produces non-deterministic random numbers
    std::random_device rd;

    // Standard mersenne_twister_engine seeded with rd()
    std::mt19937 rng(rd());

    // Produces random integer values, uniformly distributed on the closed interval [a, b]
    std::uniform_int_distribution<int> uni(begin, end);
    return uni(rng);
}

std::wstring stringToWstring(const std::string& t_str) {
    // converter setup
    typedef std::codecvt_utf8<wchar_t> convert_type;
    std::wstring_convert<convert_type, wchar_t> converter;
    return converter.from_bytes(t_str);
}