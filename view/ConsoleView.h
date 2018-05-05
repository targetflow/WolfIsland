//
// Created by Alex Orlovskyi on 22.04.18.
//

#ifndef CPP_CONSOLEVIEW_H
#define CPP_CONSOLEVIEW_H

#include <iostream>
#include "../model/include/Field.h"
#include "BaseView.h"

class ConsoleView: public BaseView {
public:
    ConsoleView(Field* field);
    virtual ~ConsoleView();

    virtual void displayField();

private:
    Field* field;
};


#endif //CPP_CONSOLEVIEW_H
