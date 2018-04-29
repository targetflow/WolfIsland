//
// Created by Alex Orlovskyi on 21.04.18.
//

#include "Controller.h"
#include <ctime>
//#include <random>
#include "../utils/utils.h"


Controller::Controller(int nRabbits, int nMWolves, int nWWolves, int cOfFences) {
    this->field = Field();
    initializeField(nRabbits, nWWolves );
}

Controller::~Controller() = default;

void Controller::execute(int numberOfSteps) {
    for (unsigned long i = 0; i < numberOfSteps; i++)
        nextStep(i+1);
}

void Controller::initializeField(int nRabbits, int nWWolves)
{
//    std::random_device rd;     // only used once to initialise (seed) engine
//    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
//    std::uniform_int_distribution<unsigned long> uni(0, 399); // guaranteed unbiased

    for(int i = 0; i < nRabbits; i++)
    {
        unsigned long index = random_number(0,399);
        field.getCells()->at(index).getRabbits()->emplace_back(Rabbit());
//        std::cout << "Rabbit added to: [" << field.getCells()->at(index).getCoordinates()[0] << ", " <<
//                  field.getCells()->at(index).getCoordinates()[1] << "]." << std::endl;
//        std::cout << field.getCells()->at(index).getRabbits()->size() << std::endl;
    }
    for(int i=0;i<nWWolves;i++){
        unsigned long index = random_number(0,399);
        field.getCells()->at(index).getWolf_W()->emplace_back(Wolf_W());

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
    rabbit_spread();
    calculateMoveDecisions(); // фаза прийняття рішень
    performMoves(); // фаза переходів
    Wolf_WMoveDecisions();
    performMovesforWolf_W();

    std::cout << "Step №" << numberOfStep << std::endl;
    printFieldToConsole();
}
std::vector<int> Controller::makeListOfAvailableStepsForWolf_W(int cellNumb) {
    auto listOfAvailableStepsForWolf_W = calculateNeighbourCells(cellNumb);
    listOfAvailableStepsForWolf_W.emplace_back(cellNumb);
    return listOfAvailableStepsForWolf_W;

}
std::vector<int> Controller::makeListOfAvailableStepsForRabbit(int cellNumb) {
    auto listOfAvailableStepsForRabbit = calculateNeighbourCells(cellNumb);
    listOfAvailableStepsForRabbit.emplace_back(cellNumb);
    return listOfAvailableStepsForRabbit;
}

std::vector<int> Controller::calculateNeighbourCells(int cellNumb) {
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
            for (auto & rabbit : *rabbitVec)
            {
                rabbit.chooseMoveDirection(makeListOfAvailableStepsForRabbit(cellNumb));
            }
            //std::cout << field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits()->at(0).getChosenMoveDirection() << std::endl;
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
            for (auto & rabbit : *rabbitVec)
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
    }
}
void Controller::rabbit_spread() {
    for(int cellNumb = 0; cellNumb < 400; cellNumb++){
        srand(time(NULL));
        long i = random()%5;
        if(i==1){
            auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits();

            if(rabbitVec->size()==1){
                field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits()->emplace_back(Rabbit());
            }
            else{
                continue;
            }
        }

    }}

int Controller::chooseMoveDirectionforWolf_W(std::vector<int> listOfAvailableSteps, int cellNumber){
    for(int i=0;i<listOfAvailableSteps.size();i++){
        int numberOfAvailableStep = listOfAvailableSteps[i];
        auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(numberOfAvailableStep)).getRabbits();
        if(!rabbitVec->empty()){
            auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getWolf_W();
            for(auto & wolf_w:*Wolf_WVec){
                wolf_w.setChosenMoveDirection(numberOfAvailableStep);
                break;}

        }
    }
    auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getWolf_W();
    for(auto & wolf_w:*Wolf_WVec){
        int chosen = wolf_w.getChosenMoveDirection() ;
        if(chosen ==-1){
            wolf_w.setChosenMoveDirection(static_cast<int>(random_number(0, 399)));
        }
    }
}



void Controller:: Wolf_WMoveDecisions(){
    for(int cellNumber = 0;cellNumber<400;cellNumber++){
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getWolf_W();
        if(!Wolf_WVec->empty()){
            for(auto & wolf_w:*Wolf_WVec){
                wolf_w.chooseMoveDirectionforWolf_W(makeListOfAvailableStepsForWolf_W(cellNumber), cellNumber) ;
            }
        }
    }
}
void Controller::performMovesforWolf_W() {

}