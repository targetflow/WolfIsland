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
    std::vector<int> makeListOfAvailableStepsForRabbit(int cellNumb);
    std::vector<int> makeListOfAvailableStepsForWolf_W(int cellNumb);

private:
    Field field;
    void performMovesforWolf_W();
    void initializeField(int nRabbits, int nWWolves);
    void printFieldToConsole();
    void nextStep(unsigned long numberOfStep);
    void rabbit_spread();
    std::vector<int> calculateNeighbourCells(int cellNumb);
    void Wolf_WMoveDecisions();
    void calculateMoveDecisions();
    void performMoves();
    int chooseMoveDirectionforWolf_W(std::vector<int> listOfAvailableSteps, int cellNumber);
};


#endif //CPP_CONTROLLER_H
