//
// Created by Alex Orlovskyi on 22.04.18.
//

#include "ConsoleView.h"

ConsoleView::ConsoleView() = default;

ConsoleView::~ConsoleView() = default;

void ConsoleView::printFieldToConsole(Field field) {
    std::string fieldView;
    std::string cellContent;
    int countOfRabbits, countOfWolvesW, countOfWolvesM;
    for (int i = 0; i < 400; i++) {
        //construct Cell contents

        if (field.getCells()->at(static_cast<unsigned long>(i)).isFence()) {
            cellContent += "F";
        }
        else {
            if(!field.getCells()->at(static_cast<unsigned long>(i)).getRabbits()->empty()) {
                countOfRabbits = static_cast<int>(field.getCells()->at(static_cast<unsigned long>(i)).getRabbits()->size());
                for (int j = 0; j < countOfRabbits; j++) {
                    cellContent += "R";
                }
            }

            if(!field.getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->empty()) {
                countOfWolvesW = static_cast<int>(field.getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->size());
                for (int j = 0; j < countOfWolvesW; j++) {
                    cellContent += "W";
                }
            }
            if(!field.getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->empty()) {
                countOfWolvesM = static_cast<int>(field.getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->size());
                for (int j = 0; j < countOfWolvesM; j++) {
                    cellContent += "M";
                }
            }


            if (cellContent.empty()) {
                cellContent = " ";
            }
        }

        //construct Field
        fieldView.append("[");
        fieldView.append(cellContent);
        fieldView.append("] ");
        if ((i+1) % 20 == 0)
            fieldView += "\n";

        // clear-up interation vars
        cellContent = "";
    }
    std::cout << fieldView << std::endl;
}
