//
// Created by Alex Orlovskyi on 05.05.18.
//

#ifndef CPP_GUIVIEW_H
#define CPP_GUIVIEW_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "../model/include/Field.h"

using namespace sf;

class GUIView {
    GUIView(Field field);
    virtual ~GUIView();

    void printFieldToBoard();
};

#endif //CPP_GUIVIEW_H
