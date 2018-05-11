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

class GUIView: public BaseView {
public:
    explicit GUIView(Field *_pField, RenderWindow *_pWindow);
    ~GUIView() override;

    RectangleShape* getBtnPlayStep();
    RectangleShape* getBtnSwitchAutoPlayOrPause();

    void displayField() override;
private:
    Field* pField;
    RenderWindow* pWindow;

    Sprite grassSprt; // спрайт карти
    Texture grassTxtr; // текстура карти
    Image grassImg; // зображення для трави, що покриватиме клітинку карти
    Sprite fenceSprt; // спрайт огорожі
    Texture fenceTxtr;
    Image fenceImg;
    Sprite rabbitSprt; // спрайт кроля
    Texture rabbitTxtr;
    Image rabbitImg;
    Sprite wolfMSprt; // спрайт вовка
    Texture wolfMTxtr;
    Image wolfMImg;
    Sprite wolfWSprt; // спрайт вовчиці
    Texture wolfWTxtr;
    Image wolfWImg;
    Sprite menuSprt; // спрайт вовчиці
    Texture menuTxtr;
    Image menuImg;

    RectangleShape btnPlayStep;
    RectangleShape btnSwitchAutoPlayOrPause;

    void initMenu();
    void initFieldTextures();

    void drawMap();
    void drawMenu();
    void drawAnimals();
};

#endif //CPP_GUIVIEW_H
