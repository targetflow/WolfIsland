//
// Created by Alex Orlovskyi on 21.04.18.
//

#include "Controller.h"
#include "../model/include/Field.h"
#include <iostream>

Controller::Controller(Field field) {
    this->field = field;
}

Controller::~Controller() = default;

void Controller::execute(int numberOfSteps) {
    for (int i = 0; i < numberOfSteps; i++)
        std::cout << " Perform step: " << i << std::endl;
}