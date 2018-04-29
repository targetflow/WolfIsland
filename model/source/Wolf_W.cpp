//
// Created by katya on 20/04/18.
//

#include "../include/Wolf_W.h"


Wolf_W::Wolf_W()
{
    chosenMoveDirection = -1;
}
Wolf_W::~Wolf_W()
= default;
//int Wolf_W :: chooseMoveDirection(std::vector<int> listOfAvailableSteps, int cellNumber){
//    for(int i=0;i<listOfAvailableSteps.size();i++){
//        int numberOfAvailableStep = listOfAvailableSteps[i];
//        auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(numberOfAvailableStep)).getRabbits();
//        if(!rabbitVec->empty()){
//            chosenMoveDirection = numberOfAvailableStep;
//            return chosenMoveDirection;
//            break;
//        }
//    }
//}
int Wolf_W :: getChosenMoveDirection()
{
    return chosenMoveDirection;
}

void Wolf_W :: setChosenMoveDirection(int direction)
{
    chosenMoveDirection = direction;
}

void Wolf_W :: TryToEatOrDie(){

}
void Wolf_W :: TryToMakeOffspring(){

}