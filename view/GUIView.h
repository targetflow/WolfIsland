//
// Created by Alex Orlovskyi on 05.05.18.
//

#ifndef CPP_GUIVIEW_H
#define CPP_GUIVIEW_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../model/include/Field.h"
#include "BaseView.h"

using namespace sf;

//const int HEIGHT_MAP = 20;
//const int WIDTH_MAP = 20;

class GUIView: public BaseView {
public:
    explicit GUIView(Field *field);
    ~GUIView() override;

    void displayField() override;
private:
    Field* field;
    //static sf::String TileMap[HEIGHT_MAP];
};

#endif //CPP_GUIVIEW_H
