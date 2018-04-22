//
// Created by Alex Orlovskyi on 21.04.18.
//

#ifndef CPP_CONTROLLER_H
#define CPP_CONTROLLER_H

#include "../model/include/Field.h"
#include "../view/ConsoleView.h"
#include <random>
#include <iostream>

class Controller {
public:
    explicit Controller(int nRabbits, int nMWolves, int nWWolves, int cOfFences);
    virtual ~Controller();

    void execute(int numberOfSteps = 0);
    std::vector<int> calculateNeighbourCells(int cellNumb);
private:
    Field field;
    void initializeField(int nRabbits);
    void printFieldToConsole();
    void nextStep(unsigned long numberOfStep);
    std::vector<int>* makeListOfAvailableStepsForRabbit(int cellNumb);

};


#endif //CPP_CONTROLLER_H
