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
    explicit ConsoleView(Field* field);
    ~ConsoleView() override;

    void displayField() override;

private:
    Field* field;
};


#endif //CPP_CONSOLEVIEW_H
