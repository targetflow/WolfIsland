//
// Created by katya on 04/04/18.
//

#include "controller/Controller.h"

int main(){
    const int nRabbits = 12;
    const int nMWolves = 4;
    const int nWWolves = 3;
    const int cOfFences = 30;
    const int countOfSteps = 3;

    Controller controller = Controller(nRabbits, nMWolves, nWWolves, cOfFences);
    //controller.execute(countOfSteps);
    std::vector<int> testVec;
    testVec = controller.makeListOfAvailableStepsForRabbit(399);
    for (int &i : testVec)
        std::cout << i << ' ';

}

