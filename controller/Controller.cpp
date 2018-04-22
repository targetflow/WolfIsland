//
// Created by Alex Orlovskyi on 21.04.18.
//

#include "Controller.h"
#include "../model/include/Field.h"
#include <iostream>


Controller::Controller(int nRabbits, int nMWolves, int nWWolves, int cOfFences) {
    this->field = Field();
    field.initialize(nRabbits);
//    field.getCells()->getRabbits()[1].move();
}

Controller::~Controller() = default;

void Controller::execute(int numberOfSteps) {
//    for (int i = 0; i < numberOfSteps; i++)
//        std::cout << " Perform step: " << i << std::endl;

//    for (int i = 0; i < 400; i++)
//        if(field.getCells()[i].getRabbits().empty())
//            std::cout << " There's 1+ rabbit in cell [" << field.getCells()[i].getCoordinates()[0] << ", " <<
//                      field.getCells()[i].getCoordinates()[1] << "]." << std::endl;

}

