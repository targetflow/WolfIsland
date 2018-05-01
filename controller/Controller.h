//
// Created by Alex Orlovskyi on 21.04.18.
//

#ifndef CPP_CONTROLLER_H
#define CPP_CONTROLLER_H

#include "../model/include/Field.h"
#include "../view/ConsoleView.h"
#include "../utils/utils.h"
#include <iostream>
#include <algorithm>

class Controller {
public:
    explicit Controller(int nRabbits, int nMWolves, int nWWolves, int cOfFences);
    virtual ~Controller();

    void execute(int numberOfSteps = 0);
    std::vector<int> makeListOfAvailableStepsForRabbit(int cellNumb);
    std::vector<int> makeListOfAvailableStepsForWolf_W(int cellNumb);
    std::vector<int> makeListOfAvailableStepsForWolf_M(int cellNumb);

private:
    Field field;

    void initializeField(int nRabbits, int nWWolves, int nMWolves, int cOfFences);
    void printFieldToConsole();
    void nextStep(unsigned long numberOfStep);
    std::vector<int> calculateNeighbourCellsWithoutFences(int cellNumb);

    void calculateMoveDecisions();
    void performMoves();

    // rabbits stuff
    void rabbitSpread();

    // wolves stuff
    void wolfTryToEatOrDie();
    void Wolf_MMakeOffspring();
};


#endif //CPP_CONTROLLER_H
