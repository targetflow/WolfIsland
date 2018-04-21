//
// Created by katya on 04/04/18.
//

#include "controller/Controller.h"

int main(){
    int nRabbits = 12;
    int nMWolves = 4;
    int nWWolves = 3;
    int cOfFences = 30;
    Controller controller = Controller(nRabbits, nMWolves, nWWolves, cOfFences);
    controller.execute(7);

}

