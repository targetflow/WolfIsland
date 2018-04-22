//
// Created by Alex Orlovskyi on 22.04.18.
//

#include "ConsoleView.h"

ConsoleView::ConsoleView() = default;

ConsoleView::~ConsoleView() = default;

void ConsoleView::printFieldToConsole(Field field) {
    std::string fieldView;
    for (unsigned long i = 0; i < 400; i++)
    {
        if ((i+1)%20 != 0)
            fieldView += "[ ]";
        else
            fieldView += "[ ]\n";
//        if(!field.getCells()->at(i).getRabbits()->empty())
//            std::cout << " There's 1+ rabbit in cell [" << field.getCells()->at(i).getCoordinates()[0] << ", " <<
//                      field.getCells()->at(i).getCoordinates()[1] << "]." << std::endl;
    }
    std::cout << fieldView << std::endl;
}
