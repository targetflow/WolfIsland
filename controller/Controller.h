//
// Created by Alex Orlovskyi on 21.04.18.
//

#ifndef CPP_CONTROLLER_H
#define CPP_CONTROLLER_H

#include "../model/include/Field.h"

class Controller {
public:
    Controller(Field field);
    virtual ~Controller();

    void execute(int numberOfSteps = 0);

private:
    Field field;
};


#endif //CPP_CONTROLLER_H
