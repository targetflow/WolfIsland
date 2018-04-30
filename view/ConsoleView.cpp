//
// Created by Alex Orlovskyi on 22.04.18.
//

#include "ConsoleView.h"

ConsoleView::ConsoleView() = default;

ConsoleView::~ConsoleView() = default;

void ConsoleView::printFieldToConsole(Field field) {
    std::string fieldView;
    std::string cellContent;
    unsigned long countOfRabbits;
    for (unsigned long i = 0; i < 400; i++) {
        //construct Cell contents
        if(!field.getCells()->at(i).getRabbits()->empty()) {
            countOfRabbits = field.getCells()->at(i).getRabbits()->size();
            for (unsigned long j = 0; j < countOfRabbits; j++) {
                cellContent += "R";
            }
        }
        else {
            cellContent = " ";
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
