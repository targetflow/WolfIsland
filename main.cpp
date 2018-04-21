//
// Created by katya on 04/04/18.
//

#include "controller/Controller.h"
#include "model/include/Field.h"

int main(){
    Field field = Field();
    Controller controller = Controller(field);
    controller.execute(7);

}

