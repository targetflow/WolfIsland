//
// Created by Alex Orlovskyi on 05.05.18.
//

#ifndef CPP_GUIVIEW_H
#define CPP_GUIVIEW_H

#include <iostream>
#include <TGUI/TGUI.hpp>
#include "../model/include/Field.h"
#include "BaseView.h"
#include "map.h"

using namespace sf;

class GUIView: public BaseView {
public:
    explicit GUIView(Field *_pField, RenderWindow *_pWindow, tgui::Gui *_pTGUI);
    ~GUIView() override;


    void displayField() override;
private:
    Field* pField;
    RenderWindow* pWindow;
    tgui::Gui *pTGUI;

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

    tgui::Button::Ptr pTgBtnPlayStep;
    tgui::Button::Ptr pTgBtnPlayAuto;
    tgui::Button::Ptr pTgBtnReset;
    tgui::TextBox::Ptr TextRabbit;
    tgui::TextBox::Ptr TextWolf_M;
    tgui::TextBox::Ptr TextWolf_W;
    tgui::TextBox::Ptr TextFence;




    void initMenu();
    void initFieldTextures();

    void drawMap();
    void drawMenu();
    void drawAnimals();
};

#endif //CPP_GUIVIEW_H
