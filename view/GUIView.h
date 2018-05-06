//
// Created by Alex Orlovskyi on 05.05.18.
//

#ifndef CPP_GUIVIEW_H
#define CPP_GUIVIEW_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../model/include/Field.h"
#include "BaseView.h"
#include "map.h"

using namespace sf;

//const int HEIGHT_MAP = 20;
//const int WIDTH_MAP = 20;

class GUIView: public BaseView {
public:
    explicit GUIView(Field *_pField, RenderWindow *_pWindow);
    ~GUIView() override;

    void displayField() override;
private:
    Field* pField;
    RenderWindow* pWindow;
    Sprite grassSprt; // спрайт карти
    Texture grassTxtr; // текстура карти
    Image grassImg; // зображення для клітинки карти
    //String TileMap[HEIGHT_MAP];

    void drawMap();
};

#endif //CPP_GUIVIEW_H
