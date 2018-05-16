//
// Created by Alex Orlovskyi on 21.04.18.
//

#ifndef CPP_CONTROLLER_H
#define CPP_CONTROLLER_H

#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "../model/include/Field.h"
#include "../view/ConsoleView.h"
#include "../view/GUIView.h"
#include "../view/BaseView.h"
#include "../utils/utils.h"


class Controller {
public:
    Controller();
    virtual ~Controller();

    void execute();
    std::vector<int> makeListOfAvailableStepsForRabbit(int cellNumb);
    std::vector<int> makeListOfAvailableStepsForWolf_W(int cellNumb);
    std::vector<int> makeListOfAvailableStepsForWolf_M(int cellNumb);
    GUIView* getPGUIView();
private:
    Field field;
    sf::RenderWindow window;
    tgui::Gui TGUI;
    BaseView* pView;
    // init parameters
    int currentStepNumber;
    String windowTitle;
    int initNumbOfRabbits;
    int initNumbOfMWolves;
    int initNumbOfWWolves;
    int initNumbOfFences;
    bool useGUI;
    unsigned int FPS;
    Time delayTimeInSeconds;

    void initSimulationParams();
    void initWindow();
    void initField(int nRabbits, int nWWolves, int nMWolves, int cOfFences);
    void restartField();
    void displayField();
    void nextStep();

    // moves
    std::vector<int> calculateNeighbourCellsWithoutFences(int cellNumb);
    void calculateMoveDecisions();
    void performMoves();

    // rabbits stuff
    void rabbitSpread();

    // wolves stuff
    void wolfTryToEatOrDie();
    void Wolf_MMakeOffspring();
    void initView();

    // global current field parameters calculation
    int countOfRabbitsOnField();
    int countOfWolf_WOnField();
    int countOfWolf_MOnField();
    int countOfFencesOnField();
};

#endif //CPP_CONTROLLER_H
