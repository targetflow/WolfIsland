//
// Created by Alex Orlovskyi on 21.04.18.
//

#include "Controller.h"

Controller::Controller(int nRabbits, int nMWolves, int nWWolves, int cOfFences) {
    this->field = Field();
    initializeField(nRabbits);
//    field.getCells()->getRabbits()[1].move();
}

Controller::~Controller() = default;

void Controller::execute(int numberOfSteps) {
//    for (int i = 0; i < numberOfSteps; i++)
//        std::cout << " Perform step: " << i << std::endl;

    for (unsigned long i = 0; i < 400; i++)
        if(!field.getCells()->at(i).getRabbits()->empty())
            std::cout << " There's 1+ rabbit in cell [" << field.getCells()->at(i).getCoordinates()[0] << ", " <<
                      field.getCells()->at(i).getCoordinates()[1] << "]." << std::endl;

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

    std::cout << "Field initialized" << std::endl;
    printFieldToConsole();
}

void Controller::printFieldToConsole() {
    ConsoleView consoleView = ConsoleView();
    consoleView.printFieldToConsole(this->field);
}
