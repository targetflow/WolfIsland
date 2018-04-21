//
// Created by katya on 20/04/18.
//

#ifndef CPP_FIELD_H
#define CPP_FIELD_H
#include "Cell.h"


class Field{
private:
    Field(); // Disallow instantiation outside of the class.
public:

    static auto instance(){
        static Field field;
        return field;
    }
    Cell * cells[400];
protected:
};

#endif //CPP_FIELD_H
