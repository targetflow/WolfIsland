//
// Created by katya on 20/04/18.
//

#ifndef CPP_FIELD_H
#define CPP_FIELD_H
#include "Cell.h"
//https://codereview.stackexchange.com/questions/173929/modern-c-singleton-template/173935#173935

class Field{
private:
    Field();
public:

    static auto instance(){
        static Field field;
        return field;
    }
    Cell * cells[400];
protected:
};

#endif //CPP_FIELD_H
