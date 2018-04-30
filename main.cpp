//
// Created by katya on 04/04/18.
//

#include "controller/Controller.h"

int main(){
    const int nRabbits = 12;
    const int nMWolves = 4;
    const int nWWolves = 3;
    const int cOfFences = 5;
    const int countOfSteps = 3;

    Controller controller = Controller(nRabbits, nMWolves, nWWolves, cOfFences);
    controller.execute(countOfSteps);
    // test2
//    std::vector<int> a;
//    std::vector<int> b;
//    a.emplace_back(1);
//    a.emplace_back(2);
//    a.emplace_back(3);
//    b.emplace_back(4);
//    b.emplace_back(5);
//    b.emplace_back(6);
//    for (int &i : a)
//        std::cout << i << ' ';
//    std::cout << std::endl;
//    for (int &i : b)
//        std::cout << i << ' ';
//    std::cout << "New next" << std::endl;
//    a.insert(a.end(), std::make_move_iterator(b.begin()), std::make_move_iterator(b.begin()+1));
//    b.erase(b.begin(), b.begin()+1);
//    for (int &i : a)
//        std::cout << i << ' ';
//    std::cout << std::endl;
//    for (int &i : b)
//        std::cout << i << ' ';
    // test
//    std::vector<int> testVec;
//    testVec = controller.makeListOfAvailableStepsForRabbit(399);
//    for (int &i : testVec)
//        std::cout << i << ' ';

//srand(time(NULL));
//long i = random()%5;
//std::cout<<i;
}

