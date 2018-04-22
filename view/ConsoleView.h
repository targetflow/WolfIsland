//
// Created by Alex Orlovskyi on 22.04.18.
//

#ifndef CPP_CONSOLEVIEW_H
#define CPP_CONSOLEVIEW_H

#include "../model/include/Field.h"
#include <iostream>

class ConsoleView {
public:
    ConsoleView();
    virtual ~ConsoleView();

    void printFieldToConsole(Field field);
};


#endif //CPP_CONSOLEVIEW_H
