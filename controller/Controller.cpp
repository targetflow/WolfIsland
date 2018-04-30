//
// Created by Alex Orlovskyi on 21.04.18.
//

#include "Controller.h"

Controller::Controller(int nRabbits, int nMWolves, int nWWolves, int cOfFences) {
    this->field = Field();
    initializeField(nRabbits, nWWolves, cOfFences);
}

Controller::~Controller() = default;

void Controller::execute(int numberOfSteps) {
    for (unsigned long i = 0; i < numberOfSteps; i++)
        nextStep(i+1);
}

void Controller::initializeField(int nRabbits, int nWWolves, int cOfFences)
{
    int index;
    for(int i = 0; i < nRabbits; i++) {
        index = random_number(0, 399);
        field.getCells()->at(static_cast<unsigned long>(index)).getRabbits()->emplace_back(Rabbit());
    }
    for(int i = 0; i < nWWolves; i++) {
        index = random_number(0, 399);
        field.getCells()->at(static_cast<unsigned long>(index)).getWolf_W()->emplace_back(Wolf_W());
    }
    for(int i = 0; i < cOfFences; i++) {
        index = random_number(0, 399);
        field.getCells()->at(static_cast<unsigned long>(index)).setFence(true);
    }

    std::cout << "Field initialized." << std::endl;
    printFieldToConsole();
}

void Controller::printFieldToConsole() {
    ConsoleView consoleView = ConsoleView();
    consoleView.printFieldToConsole(field);
}

void Controller::nextStep(unsigned long numberOfStep) {
    // calculate decisions
    rabbitSpread();
    calculateMoveDecisions(); // фаза прийняття рішень
    performMoves(); // фаза переходів
//    Wolf_WMoveDecisions();
//    performMovesforWolf_W();

    std::cout << "Step №" << numberOfStep << std::endl;
    printFieldToConsole();
}

std::vector<int> Controller::makeListOfAvailableStepsForWolf_W(int cellNumb) {
    auto neighbourCells = calculateNeighbourCellsWithoutFences(cellNumb); // (інти) номери доступних клітин з поточної
    std::vector<int> listOfAvailableStepsForWolf_W;
    bool rabbitExplored = false;
    for (auto& cllNmb: neighbourCells) {
        // якщо є хочаб один заєць на горизонті
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
    // lambdas
    auto east = [](int numb) { return numb % 20 == 19 ? numb - 19 : numb + 1; };
    auto west = [](int numb) { return numb % 20 == 0 ? numb + 19 : numb - 1; };
    auto north = [](int numb) { return numb < 20 ? numb + 380 : numb - 20; };
    auto south = [](int numb) { return numb > 379 ? numb - 380 : numb + 20; };

    listOfNeighbours.emplace_back(east(cellNumb));
    listOfNeighbours.emplace_back(west(cellNumb));
    listOfNeighbours.emplace_back(north(cellNumb));
    listOfNeighbours.emplace_back(south(cellNumb));
    listOfNeighbours.emplace_back(east(south(cellNumb)));
    listOfNeighbours.emplace_back(west(south(cellNumb)));
    listOfNeighbours.emplace_back(east(north(cellNumb)));
    listOfNeighbours.emplace_back(west(north(cellNumb)));

    for (auto& cllNmb: listOfNeighbours) {
        if (field.getCells()->at(static_cast<unsigned long>(cllNmb)).isFence()) {
            auto vec = listOfNeighbours;
            vec.erase(std::remove(vec.begin(), vec.end(), cllNmb), vec.end());
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

        //Wolf_W
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W();
        if(!Wolf_WVec->empty()){
            for(auto& wolf_w: *Wolf_WVec)
            {
                wolf_w.chooseMoveDirection(makeListOfAvailableStepsForWolf_W(cellNumb));
            }
        }
    }
    std::cout << "Calc end" << std::endl;
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
                // якщо заєць вирішує лишитись тут же, то скіпнути виконання поточної ітерації щоб уникнути зайвих операцій
                int rabbitDecision = rabbit.getChosenMoveDirection();
                std::cout << "Rabbit decision is: " << rabbitDecision << std::endl;
                if(rabbitDecision == cellNumb or rabbitDecision < 0)
                    continue;
                else {
                    auto *destRabbitList = field.getCells()->at(static_cast<unsigned long>(rabbitDecision)).getRabbits();
                    std::cout << "Rabbit decision - go to: " << rabbitDecision << std::endl;
                    std::cout << "Dest v size: " << destRabbitList->size() << std::endl;
                    destRabbitList->insert(destRabbitList->end(), std::make_move_iterator(rabbitVec->begin()), std::make_move_iterator(rabbitVec->begin()+1));
                    std::cout << "Dest v size after insertion: " << destRabbitList->size() << std::endl;
                    rabbitVec->erase(rabbitVec->begin(), rabbitVec->begin()+1);
                    std::cout << "Curr v size after deletion: " << rabbitVec->size() << std::endl;
                    rabbit.setChosenMoveDirection(-2); // впевнитись, що цей кріль вже не буде задіяний в move на поточній ітерації.
                }
            }
        }

        //Wolf_W

    }
}

void Controller::rabbitSpread() {
    for(int cellNumb = 0; cellNumb < 400; cellNumb++) {
        long i = random_number(1, 5);
        if(i == 1) {
            auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits();
            if(rabbitVec->size() == 1) {
                field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits()->emplace_back(Rabbit());
            }
            else {
                continue;
            }
        }
    }
}

void Controller::performMovesforWolf_W() {
    for(int cellNumber = 0; cellNumber < 400; cellNumber++) {
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getWolf_W();
        if(!Wolf_WVec->empty()) {
            for(auto& wolf_w: *Wolf_WVec) {
                int chosenNumber = wolf_w.getChosenMoveDirection();
                field.getCells()->at(static_cast<unsigned long>(chosenNumber)).getWolf_W()->emplace_back(Wolf_W());
                Wolf_WVec->erase(Wolf_WVec->begin(), Wolf_WVec->begin()+1);
                auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(chosenNumber)).getRabbits();
                if(rabbitVec->empty()) {
                    wolf_w.setHealth((wolf_w.getHealth() - 0, 1));
                }
                else{
                    rabbitVec->pop_back();
                    wolf_w.setHealth((wolf_w.getHealth() + 1));
                }
            }
        }
    }
}
