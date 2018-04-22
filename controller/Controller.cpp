//
// Created by Alex Orlovskyi on 21.04.18.
//

#include "Controller.h"

Controller::Controller(int nRabbits, int nMWolves, int nWWolves, int cOfFences) {
    this->field = Field();
    initializeField(nRabbits);
}

Controller::~Controller() = default;

void Controller::execute(int numberOfSteps) {
    for (unsigned long i = 0; i < numberOfSteps; i++)
        nextStep(i+1);
}

void Controller::initializeField(int nRabbits)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<unsigned long> uni(0, 399); // guaranteed unbiased

    for(int i = 0; i < nRabbits; i++)
    {
        unsigned long index = uni(rng);
        field.getCells()->at(index).getRabbits()->emplace_back(Rabbit());
//        std::cout << "Rabbit added to: [" << field.getCells()->at(index).getCoordinates()[0] << ", " <<
//                  field.getCells()->at(index).getCoordinates()[1] << "]." << std::endl;
//        std::cout << field.getCells()->at(index).getRabbits()->size() << std::endl;
    }

    std::cout << "Field initialized." << std::endl;
    printFieldToConsole();
}

void Controller::printFieldToConsole() {
    ConsoleView consoleView = ConsoleView();
    consoleView.printFieldToConsole(this->field);
}

void Controller::nextStep(unsigned long numberOfStep) {
    std::cout << "Step №" << numberOfStep << std::endl;
    printFieldToConsole();
}
