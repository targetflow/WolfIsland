//
// Created by Alex Orlovskyi on 21.04.18.
//

#ifndef CPP_CONTROLLER_H
#define CPP_CONTROLLER_H

#include "../model/include/Field.h"
#include <iostream>

class Controller {
public:
    explicit Controller(int nRabbits, int nMWolves, int nWWolves, int cOfFences);
    virtual ~Controller();

    void execute(int numberOfSteps = 0);

private:
    Field field;
};


#endif //CPP_CONTROLLER_H
