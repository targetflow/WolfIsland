/**
 * WolfIsland environment modeling project.
 *
 * Copyright 2018 by Kateryna Pereverzeva <katya.pereverzeva2109@gmail.com>
 * Copyright 2018 by Oleksandr Orlovskyi <orlovskyi.alex@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 =========================================================================== */

// This file describes methods that determine how the program behaves,
// binds all the basic processes to each other and performs the steps in the program.

#ifndef CPP_CONTROLLER_H
#define CPP_CONTROLLER_H

#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "../../model/include/Field.h"
#include "../../view/ConsoleView.h"
#include "../../view/GUIView.h"
#include "../../view/BaseView.h"
#include "../../utils/utils.h"

// Controller - class that accepts input and converts it to commands for the model and view
class Controller {
public:
    Controller();
    virtual ~Controller();

    // controls the execution of the program in console and GUI mode
    void execute();

    //makes list of closest cells from the current cell (which are not blocked by fences)
    std::vector<int> makeListOfAvailableStepsForRabbit(int cellNumb);

    // makes list of the nearest cells where rabbit is available
    std::vector<int> makeListOfAvailableStepsForWolf_W(int cellNumb);

    // makes list of the nearest cells where at least one female wolf or rabbit is available
    std::vector<int> makeListOfAvailableStepsForWolf_M(int cellNumb);

    GUIView* getPGUIView(); // pointer which helps us to call GUIView from Controller
private:
    Field field; // main simulation field
    sf::RenderWindow window;  // main window
    tgui::Gui TGUI; // TGUI elements controller
    BaseView* pView; // pointer which helps us to call gui/console view according to user's choise made in config

    // init parameters
    int currentStepNumber;
    String windowTitle;
    int initNumbOfRabbits; // contains count of rabbits on field
    int initNumbOfMWolves; // contains count of male wolves on field
    int initNumbOfWWolves; // contains count of male wolves on field
    int initNumbOfFences; // contains count of fences on field
    bool useGUI; // indicates play mode (GUI or console)
    unsigned int FPS; // contains simulation's frame rate
    Time delayTimeInSeconds; // contains performance delay in seconds

    // fill basic simulation parameters by extracting necessary information from the file
    void initSimulationParams();

    // creates the gui and attach it to the window
    void initWindow();

    // initializes the field with counts of animals and fences
    void initField(int nRabbits, int nWWolves, int nMWolves, int cOfFences);

    // clears current game data and initializes field and parameters one more time from config.initParams.json
    void restartField();

    // draw all field elements and display it on output channel (monitor)
    void displayField();

    // performs next step in simulation
    void nextStep();

    // moves
    // makes vector from neighbour cell numbers, which do not have a fence
    std::vector<int> calculateNeighbourCellsWithoutFences(int cellNumb);

    // decides where the animal agents should go at next step
    void calculateMoveDecisions();

    // performs moves for agents according to chosen paths
    void performMoves();

    // rabbits stuff
    // spreads rabbits
    void rabbitSpread();

    // wolves stuff
    // allows the wolf to eat and check if wolf is ready to die
    void wolfTryToEatOrDie();

    // checks the possibility of making offspring and executes it
    void Wolf_MMakeOffspring();

    // initializes the program window due to selected playback parameter
    void initView();

    // global current field parameters calculation
    // counts how much rabbits are on the field
    int countOfRabbitsOnField();

    //counts how much female wolves are on the field
    int countOfWolf_WOnField();

    //counts how much male wolves are on the field
    int countOfWolf_MOnField();

    //counts how much fences are on the field
    int countOfFencesOnField();
};

#endif //CPP_CONTROLLER_H
