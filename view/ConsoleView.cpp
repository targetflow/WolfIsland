//
// Created by Alex Orlovskyi on 22.04.18.
//

#include "ConsoleView.h"

ConsoleView::ConsoleView(Field *_pField) {
    this->pField = _pField;
}

ConsoleView::~ConsoleView() = default;

void ConsoleView::displayField() {
    std::string fieldView;
    std::string cellContent;
    int countOfRabbits, countOfWolvesW, countOfWolvesM;
    for (int i = 0; i < 400; i++) {
        //construct Cell contents

        if (pField->getCells()->at(static_cast<unsigned long>(i)).isFence()) {
            cellContent += "F";
        }
        else {
            if(!pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->empty()) {
                countOfRabbits = static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->size());
                for (int j = 0; j < countOfRabbits; j++) {
                    cellContent += "R";
                }
            }
            if(!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->empty()) {
                countOfWolvesW = static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->size());
                for (int j = 0; j < countOfWolvesW; j++) {
                    cellContent += "W";
                }
            }
            if(!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->empty()) {
                countOfWolvesM = static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->size());
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
