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

#include "Controller.h"

Controller::Controller() {
    this->field = Field();
    initSimulationParams();
    initView();
    initField(initNumbOfRabbits, initNumbOfWWolves, initNumbOfMWolves, initNumbOfFences);
}

Controller::~Controller() {
    delete pView;
}

void Controller::execute() {
    bool keepExecuting = false; // variable which indicates 'pause' and 'continue' states
    if (useGUI) {
        // perform one step when "PLayStep" button is clicked
        TGUI.get("PlayStep")->connect("clicked", &Controller::nextStep, this);

        // change indicate variable keepExecuting to true when "PlayAuto" so program will be able to work automatically
        TGUI.get("PlayAuto")->connect("clicked", [&keepExecuting](bool){ keepExecuting = !keepExecuting;}, keepExecuting);

        //restart program executing when "Reset simulation" button is pressed
        TGUI.get("ResetSimulation")->connect("clicked", &Controller::restartField, this);

        // labels to show information about current state of the field
        tgui::Label::Ptr labelCurrentStep;
        tgui::Label::Ptr labelRabbit;
        tgui::Label::Ptr labelWolf_W;
        tgui::Label::Ptr labelWolf_M;
        tgui::Label::Ptr labelFences;

        // main loop
        while (window.isOpen()) {
            Event event {};
            while (window.pollEvent(event)) {
                switch (event.type) {
                    // window resized:
                    case Event::Resized:
                        getPGUIView()->displayField();
                        break;

                    // window closed
                    case Event::Closed:
                        window.close();
                        break;

                    // we don't process other types of events
                    default:
                        break;
                }
                TGUI.handleEvent(event); // Pass the event to the widgets
            }

            if (keepExecuting) {
                sleep(delayTimeInSeconds);
                nextStep();

                // if "PlayAuto" button clicked, text will change to "Stop simulation"
                TGUI.get<tgui::Button>("PlayAuto")->setText(L"Stop simulation");
                TGUI.get<tgui::Button>("PlayStep")->disable();
                TGUI.get<tgui::Button>("ResetSimulation")->disable();
            }
            else {
                // if "PlayAuto" button clicked one more time, text will change to "Auto simulation"
                TGUI.get<tgui::Button>("PlayAuto")->setText(L"Auto simulation");
                TGUI.get<tgui::Button>("PlayStep")->enable();
                TGUI.get<tgui::Button>("ResetSimulation")->enable();
            }

            // fill "labelCurrentStep" label with text and number of current step
            labelCurrentStep = TGUI.get<tgui::Label>("labelCurrentStep");
            labelCurrentStep->setText(L"Current step: " + std::to_string(currentStepNumber));

            // fill "labelRabbits" label with text and count of rabbits on field
            labelRabbit = TGUI.get<tgui::Label>("labelRabbits");
            labelRabbit->setText(L"Count of rabbits: " + std::to_string(countOfRabbitsOnField()));
            labelRabbit->disable();

            // fill "labelWolf_W" label with text and count of female wolves on field
            labelWolf_W = TGUI.get<tgui::Label>("labelWolf_W");
            labelWolf_W->setText(L"Count of female wolves: " + std::to_string(countOfWolf_WOnField()));
            labelWolf_W->disable();

            //f ill "labelWolf_M" label with text and count of male wolves on field
            labelWolf_M = TGUI.get<tgui::Label>("labelWolf_M");
            labelWolf_M->setText(L"Count of male wolves: " + std::to_string(countOfWolf_MOnField()));
            labelWolf_M->disable();

            // fill "labelFences" label with text and count of fences on field
            labelFences = TGUI.get<tgui::Label>("labelFences");
            labelFences->setText(L"Count of fences: " + std::to_string(countOfFencesOnField()));
            labelFences->disable();

            TGUI.draw(); // Draw all widgets
            window.display();
        }
    } else { // in console mode
        nextStep();
    }
}

void Controller::initSimulationParams() {
    // load params from JSON
    FILE* fp = fopen("../config/initParams.json", "r");
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);
    fclose(fp);

    // extract necessary information from the file
    currentStepNumber = 0;
    useGUI = d["generalProgramParams"]["useGUI"].GetBool();
    initNumbOfRabbits = d["simulationParams"]["numberOfRabbits"].GetUint();
    initNumbOfMWolves = d["simulationParams"]["numberOfMWolves"].GetUint();
    initNumbOfWWolves = d["simulationParams"]["numberOfWWolves"].GetUint();
    initNumbOfFences = d["simulationParams"]["numberOfFences"].GetUint();
    windowTitle = stringToWstring(d["mainWindowParams"]["windowTitle"].GetString());
    FPS = d["mainWindowParams"]["FPS"].GetUint(); // 60 optimally.
    delayTimeInSeconds = seconds(d["mainWindowParams"]["delayTimeInSeconds"].GetUint());
}

void Controller::initWindow() {
    window.create(VideoMode(896, 640), windowTitle);
    window.setFramerateLimit(FPS);
    TGUI.setWindow(window);
}

void Controller::initView() {
    if(useGUI) {
        initWindow();
        pView = new GUIView(&field, &window, &TGUI);
    } else {
        pView = new ConsoleView(&field);
    }
}

void Controller::initField(int nRabbits, int nWWolves, int nMWolves, int cOfFences)
{
    int index;
    bool animalAcquireHome = false; // variable which indicates if animal was already set on field

    // set some fences to the random cells on field
    for (int i = 0; i < cOfFences; i++) {
        index = random_number(0, 399);
        field.getCells()->at(static_cast<unsigned long>(index)).setFence(true);
    }

    // set rabbits to the random cells on field
    for (int i = 0; i < nRabbits; i++) {
        while (!animalAcquireHome) {
            index = random_number(0, 399);
            if (!field.getCells()->at(static_cast<unsigned long>(index)).isFence()) {
                field.getCells()->at(static_cast<unsigned long>(index)).getRabbits()->emplace_back(Rabbit());
                animalAcquireHome = true;
            }
        }
        animalAcquireHome = false;
    }

    // set female wolves to the random cells on field
    for (int i = 0; i < nWWolves; i++) {
        while (!animalAcquireHome) {
            index = random_number(0, 399);
            if (!field.getCells()->at(static_cast<unsigned long>(index)).isFence()) {
                field.getCells()->at(static_cast<unsigned long>(index)).getWolf_W()->emplace_back(Wolf_W());
                animalAcquireHome = true;
            }
        }
        animalAcquireHome = false;
    }

    // set male wolves to the random cells on field
    for (int i = 0; i<nMWolves; i++){
        while (!animalAcquireHome) {
            index = random_number(0, 399);
            if (!field.getCells()->at(static_cast<unsigned long>(index)).isFence()) {
                field.getCells()->at(static_cast<unsigned long>(index)).getWolf_M()->emplace_back(Wolf_M());
                animalAcquireHome = true;
            }
        }
        animalAcquireHome = false;
    }

    std::cout << "New field initialized." << std::endl;
    displayField();
}

void Controller::restartField() {
    std::cout << "Restarting field ..." << std::endl;
    for(int index = 0; index < 400; index++) {
        field.getCells()->at(static_cast<unsigned long>(index)).getRabbits()->clear();
        field.getCells()->at(static_cast<unsigned long>(index)).getWolf_W()->clear();
        field.getCells()->at(static_cast<unsigned long>(index)).getWolf_M()->clear();
        if (field.getCells()->at(static_cast<unsigned long>(index)).isFence())
            field.getCells()->at(static_cast<unsigned long>(index)).setFence(false);
    }
    initSimulationParams();
    initField(initNumbOfRabbits, initNumbOfWWolves, initNumbOfMWolves, initNumbOfFences);
    TGUI.get<tgui::Button>("PlayAuto")->setText("Auto Play");
}

void Controller::displayField() {
    pView->displayField();
}

void Controller::nextStep() {
    // animation. TODO: FIX A BUG: if you press on a button multiple times in a second, button corrupts.
//    if (useGUI) {
//        TGUI.get("PlayStep")->showWithEffect(tgui::ShowAnimationType::Fade, sf::milliseconds(900));
//    }

    // calculate decisions
    rabbitSpread();
    Wolf_MMakeOffspring();
    wolfTryToEatOrDie();
    calculateMoveDecisions(); // decision making phase
    performMoves(); // moving phase
    currentStepNumber += 1;

    std::cout << "Step №" << currentStepNumber << std::endl;
    displayField();
}

std::vector<int> Controller::makeListOfAvailableStepsForWolf_W(int cellNumb) {
    auto neighbourCells = calculateNeighbourCellsWithoutFences(cellNumb); // available cell numbers from the current cell
    std::vector<int> listOfAvailableStepsForWolf_W;
    bool rabbitExplored = false;
    for (auto& cllNmb: neighbourCells) {
        // if there is at least one rabbit in the nearest cells
        if (!field.getCells()->at(static_cast<unsigned long>(cllNmb)).getRabbits()->empty())
        {
            listOfAvailableStepsForWolf_W.emplace_back(cllNmb);
            rabbitExplored = true;
        }
    }
    if (rabbitExplored)
        return listOfAvailableStepsForWolf_W;
    else
        return neighbourCells;
}

std::vector<int> Controller::makeListOfAvailableStepsForRabbit(int cellNumb) {
    auto listOfAvailableStepsForRabbit = calculateNeighbourCellsWithoutFences(cellNumb);
    listOfAvailableStepsForRabbit.emplace_back(cellNumb);
    return listOfAvailableStepsForRabbit;
}

std::vector<int> Controller::calculateNeighbourCellsWithoutFences(int cellNumb) {
    std::vector<int> listOfNeighbours;
    auto east = [](int numb) { return numb % 20 == 19 ? numb - 19 : numb + 1; };
    auto west = [](int numb) { return numb % 20 == 0 ? numb + 19 : numb - 1; };
    auto north = [](int numb) { return numb < 20 ? numb + 380 : numb - 20; };
    auto south = [](int numb) { return numb > 379 ? numb - 380 : numb + 20; };

    // create list of cells where potentially can be fences
    listOfNeighbours.emplace_back(east(cellNumb));
    listOfNeighbours.emplace_back(west(cellNumb));
    listOfNeighbours.emplace_back(north(cellNumb));
    listOfNeighbours.emplace_back(south(cellNumb));
    listOfNeighbours.emplace_back(east(south(cellNumb)));
    listOfNeighbours.emplace_back(west(south(cellNumb)));
    listOfNeighbours.emplace_back(east(north(cellNumb)));
    listOfNeighbours.emplace_back(west(north(cellNumb)));

    // erase cells with fences
    for (auto& cllNmb: listOfNeighbours) {
        if (field.getCells()->at(static_cast<unsigned long>(cllNmb)).isFence()) {
            listOfNeighbours.erase(std::remove(listOfNeighbours.begin(), listOfNeighbours.end(), cllNmb),
                listOfNeighbours.end());
        }
    }
    return listOfNeighbours;
}

void Controller::calculateMoveDecisions()
{
    std::cout << "Calc start" << std::endl;
    for(int cellNumb = 0; cellNumb < 400; cellNumb++)
    {
        // Rabbits
        auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits();
        if(!rabbitVec->empty())
        {
            for (auto& rabbit: *rabbitVec)
            {
                rabbit.chooseMoveDirection(makeListOfAvailableStepsForRabbit(cellNumb));
            }
        }

        // Wolf_W
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W();
        if(!Wolf_WVec->empty()){
            for(auto& wolf_w: *Wolf_WVec)
            {
                wolf_w.chooseMoveDirection(makeListOfAvailableStepsForWolf_W(cellNumb));
            }
        }

        // Wolf_M
        auto Wolf_MVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M();
        if(!Wolf_MVec->empty()){
            for(auto& wolf_m: *Wolf_MVec)
            {
                wolf_m.chooseMoveDirection(makeListOfAvailableStepsForWolf_M(cellNumb));
            }
        }
    }
    std::cout << "Calc move decisions end" << std::endl;
}

void Controller::performMoves()
{
    for(int cellNumb = 0; cellNumb < 400; cellNumb++)
    {
        // Rabbits
        auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits();
        if(!rabbitVec->empty())
        {
            for (auto& rabbit: *rabbitVec)
            {
                std::cout << "Curr cell: " << cellNumb << std::endl;
                std::cout << "Curr v size: " << rabbitVec->size() << std::endl;
                int rabbitDecision = rabbit.getChosenMoveDirection();
                std::cout << "Rabbit decision is: " << rabbitDecision << std::endl;
                // if rabbit has decided not to go anywhere or has already completed the movement, skip this operation
                if(rabbitDecision == cellNumb or rabbitDecision < 0)
                    continue;
                else {
                    // get list of rabbits from destination cell
                    auto *destRabbitList = field.getCells()->at(static_cast<unsigned long>(rabbitDecision)).getRabbits();
                    std::cout << "Rabbit decision - go to: " << rabbitDecision << std::endl;
                    std::cout << "Dest v size: " << destRabbitList->size() << std::endl;
                    // move a rabbit
                    destRabbitList->insert(destRabbitList->end(), std::make_move_iterator(rabbitVec->begin()), std::make_move_iterator(rabbitVec->begin()+1));
                    std::cout << "Dest v size after insertion: " << destRabbitList->size() << std::endl;
                    // erase this rabbit from current cell
                    rabbitVec->erase(rabbitVec->begin(), rabbitVec->begin()+1);
                    std::cout << "Curr v size after deletion: " << rabbitVec->size() << std::endl;
                    rabbit.setChosenMoveDirection(-2);// make sure that this rabbit is no longer involved in the move on the current iteration.
                }
            }
        }

        // Wolf_W
        // get list of female wolves from current cell
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W();
        if(!Wolf_WVec->empty()) {
            for (auto itW = Wolf_WVec->begin(); itW != Wolf_WVec->end();) {
                // get chosen destination from every female wolf
                auto wolf_w_decision = static_cast<unsigned long>((*itW).getChosenMoveDirection());
                // if female wolf has decided not to go anywhere or has already completed the movement, skip this operation
                if (wolf_w_decision == cellNumb or wolf_w_decision < 0) {
                    ++itW;
                    continue;
                } else {
                    // move a female wolf
                    field.getCells()->at(wolf_w_decision).getWolf_W()->emplace_back((*itW));
                    // make sure that this female wolf is no longer involved in the move on the current iteration.
                    (*itW).setChosenMoveDirection(-2);
                    // erase from current cell
                    itW = Wolf_WVec->erase(itW);
                }
            }
        }

        // Wolf_M
        // get list of male wolves from current cell
        auto Wolf_MVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M();
        if(!Wolf_MVec->empty()) {
            for (auto itM = Wolf_MVec->begin(); itM != Wolf_MVec->end();) {
                // get chosen destination from every male wolf
                auto wolf_m_decision = static_cast<unsigned long>((*itM).getChosenMoveDirection());
                // if male wolf has decided not to go anywhere or has already completed the movement, skip this operation
                if (wolf_m_decision == cellNumb or wolf_m_decision < 0) {
                    ++itM;
                    continue;
                } else {
                    // move a male wolf
                    field.getCells()->at(wolf_m_decision).getWolf_M()->emplace_back((*itM));
                    // make sure that this male wolf is no longer involved in the move on the current iteration.
                    (*itM).setChosenMoveDirection(-2);
                    // erase from current cell
                    itM = Wolf_MVec->erase(itM);
                }
            }
        }
    }
    std::cout << "Perf moves off" << std::endl;
}

void Controller::rabbitSpread() {
    for(int cellNumb = 0; cellNumb < 400; cellNumb++) {
        // use pseudo-random generator to decide if rabbit will spread(1==yes)
        if(random_number(1, 5) == 1) {
            // get list of rabbits from current cell
            auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits();
            if(rabbitVec->size() == 1) {
                // insert one more rabbit
                field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits()->emplace_back(Rabbit());
            }
            else {
                continue;
            }
        }
    }
    std::cout << "Rabbit spread off" << std::endl;
}

void Controller::wolfTryToEatOrDie() {
    std::vector<Wolf_W>::iterator itW;
    std::vector<Wolf_M>::iterator itM;

    for (int cellNumber = 0; cellNumber < 400; cellNumber++){

        // Wolf_W
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getWolf_W();
        if (!Wolf_WVec->empty()) {
            for (auto& wolf_w: *Wolf_WVec) {
                // if there are at least one rabbit
                auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getRabbits();
                if (!rabbitVec->empty()) {
                    // If a wolf eats a rabbit, he will get +1 point to health
                    wolf_w.setHealth(wolf_w.getHealth()+1);
                    // the rabbit is dying
                    rabbitVec->pop_back();
                } else {
                    // If a wolf hasn't eaten a rabbit, health will decrease by 0.1 points
                    wolf_w.setHealth(static_cast<float>(wolf_w.getHealth() - 0.1));
                }
            }
            // if wolf has 0 health point, he will die
            for (itW = Wolf_WVec->begin(); itW != Wolf_WVec->end();) {
                if ((*itW).getHealth() <= 0.0f) {
                    itW = Wolf_WVec->erase(itW);
                } else {
                    ++itW;
                }
            }
        }

        // Wolf_M
        auto Wolf_MVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getWolf_M();
        if (!Wolf_MVec->empty()) {
            for (auto& wolf_m: *Wolf_MVec) {
                // if there are at least one rabbit
                auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getRabbits();
                if (!rabbitVec->empty()) {
                    // If a wolf eats a rabbit, he will get +1 point to health
                    wolf_m.setHealth(wolf_m.getHealth()+1);
                    // the rabbit is dying
                    rabbitVec->pop_back();
                } else {
                    // If a wolf hasn't eaten a rabbit, health will decrease by 0.1 points
                    wolf_m.setHealth(static_cast<float>(wolf_m.getHealth() - 0.1));
                }
            }
            // if wolf has 0 health point, he will die
            for (itM = Wolf_MVec->begin(); itM != Wolf_MVec->end();) {
                if ((*itM).getHealth() <= 0.0f) {
                    itM = Wolf_MVec->erase(itM);
                } else {
                    ++itM;
                }
            }
        }
    }
    std::cout << "TryToEatOfDie off" << std::endl;
}

std::vector<int> Controller::makeListOfAvailableStepsForWolf_M(int cellNumb) {
    // get all nearest cells without fences for current cell
    auto neighbourCells = calculateNeighbourCellsWithoutFences(cellNumb);
    std::vector<int> listOfAvailableStepsForWolf_M;
    // variable which indicates if there is at least one female wolf among the nearest cells
    bool Wolf_WExplored = false;
    for (auto& cllNmb: neighbourCells){
        // if there is at least one female wolf, add this cell to the "available" list
        if (!field.getCells()->at(static_cast<unsigned long>(cllNmb)).getWolf_W()->empty()){
            listOfAvailableStepsForWolf_M.emplace_back(cllNmb);
            Wolf_WExplored = true;
        }
    }
    if (Wolf_WExplored) {
        return listOfAvailableStepsForWolf_M;
    }
    // if female wolf wasn't explored, try to find rabbits
    else {
        // variable which indicates if there is at least one rabbit among the nearest cells
        bool rabbitExplored = false;
            for (auto& cllNmb: neighbourCells) {
                // if there is at least one rabbit, add this cell to the "available" list
                if (!field.getCells()->at(static_cast<unsigned long>(cllNmb)).getRabbits()->empty())
                {
                    listOfAvailableStepsForWolf_M.emplace_back(cllNmb);
                    rabbitExplored = true;
                }
            }
        if (rabbitExplored) {
            return listOfAvailableStepsForWolf_M;
        }
        // if any test hasn't worked, return the nearest cells
        else {
            return neighbourCells;
        }
    }
}

void Controller::Wolf_MMakeOffspring() {
    for (int cellNumb = 0; cellNumb < 399;cellNumb++) {
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W();
        auto Wolf_MVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M();
        int Wolf_WSize = static_cast<int>(Wolf_WVec->size());
        int Wolf_MSize = static_cast<int>(Wolf_MVec->size());
        bool wolf_wFound = false;

        // check if female wolf is in current cell
        if (!field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W()->empty()) {
            wolf_wFound = true;
        }
        bool wolf_mFound = false;

        // check if male wolf is in current cell
        if (!field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M()->empty()) {
            wolf_mFound = true;
        }

        // check if rabbit is in current cell
        bool rabbitFound = false;
        if (!field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits()->empty()) {
            rabbitFound = true;
        }
        int BabyCount = 0;
        if (wolf_wFound && wolf_mFound && !rabbitFound) {
            // The three tests below check the number of full pairs and the number of children that can be born
            if (Wolf_MSize == Wolf_WSize) {
                BabyCount = Wolf_MSize;
            }
            if (Wolf_MSize > Wolf_WSize) {
                BabyCount = Wolf_WSize;
            }
            if (Wolf_MSize < Wolf_WSize) {
                BabyCount = Wolf_MSize;
            }

            // randomly decide, who should be born(0==female wolf, 1==male wolf)
            for (int baby = 0; baby < BabyCount; baby++) {
                int gender = random_number(0,1);
                if (gender == 0) {
                    field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W()->emplace_back(Wolf_W());
                }
                else {
                    field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M()->emplace_back(Wolf_M());
                }
            }
        }
    }
    std::cout << "Make Offspring off" << std::endl;
}

GUIView *Controller::getPGUIView() {
    return dynamic_cast<GUIView *>(pView);
}

int Controller::countOfRabbitsOnField() {
    int count=0;
    for (int index = 0; index < 400; index++) {
        count+=field.getCells()->at(static_cast<unsigned long>(index)).getRabbits()->size();
    }
    return count;
}

int Controller::countOfWolf_MOnField() {
    int count=0;
    for (int index = 0; index < 400; index++) {
        count+=field.getCells()->at(static_cast<unsigned long>(index)).getWolf_M()->size();
    }
    return count;
}

int Controller::countOfWolf_WOnField() {
    int count=0;
    for (int index = 0; index < 400; index++) {
        count+=field.getCells()->at(static_cast<unsigned long>(index)).getWolf_W()->size();
    }
    return count;
}

int Controller::countOfFencesOnField() {
    int count=0;
    for (int index = 0; index < 400; index++) {
        if (field.getCells()->at(static_cast<unsigned long>(index)).isFence()) {
            count++;
        }
    }
    return count;
}