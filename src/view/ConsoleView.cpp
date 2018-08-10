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

#include "ConsoleView.h"

ConsoleView::ConsoleView(Field *_pField) {
    this->pField = _pField;
}

ConsoleView::~ConsoleView() = default;

void ConsoleView::displayField() {
    std::string fieldView; // variable that displays what is in the cell
    std::string cellContent; // variable that fill the cell with needed content
    int countOfRabbits, countOfWolvesW, countOfWolvesM;

    for (int i = 0; i < 400; i++) {
        //construct Cell contents
        // fill cell, that contain fence with "F" content
        if (pField->getCells()->at(static_cast<unsigned long>(i)).isFence()) {
            cellContent += "F";
        }
        else {
            // fill cell, that contain rabbit with "R" content
            if(!pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->empty()) {
                countOfRabbits = static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->size());
                for (int j = 0; j < countOfRabbits; j++) {
                    cellContent += "R";
                }
            }

            // fill cell, that contain female wolf with "W" content
            if(!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->empty()) {
                countOfWolvesW = static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->size());
                for (int j = 0; j < countOfWolvesW; j++) {
                    cellContent += "W";
                }
            }

            // fill cell, that contain male wolf with "M" content
            if(!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->empty()) {
                countOfWolvesM = static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->size());
                for (int j = 0; j < countOfWolvesM; j++) {
                    cellContent += "M";
                }
            }

            // fill empty cell with " " content
            if (cellContent.empty()) {
                cellContent = " ";
            }
        }

        // construct Field
        fieldView.append("[");
        fieldView.append(cellContent);
        fieldView.append("] ");
        if ((i+1) % 20 == 0)
            fieldView += "\n";

        cellContent = "";
    }
    std::cout << fieldView << std::endl;
}
