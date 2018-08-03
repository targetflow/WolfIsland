//
// Created by Alex Orlovskyi on 05.05.18.
//
//This file is responsible for how the program works in the GUI and initializes the menu, field, buttons and labels.
#ifndef CPP_GUIVIEW_H
#define CPP_GUIVIEW_H

#include <iostream>
#include <TGUI/TGUI.hpp>
#include <TGUI/Font.hpp>
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

    sf::Font labelsFont;

    Sprite grassSprt; // field sprite
    Texture grassTxtr; // field texture
    Image grassImg; // picture of grass for the field
    Sprite fenceSprt; // fence sprite
    Texture fenceTxtr;
    Image fenceImg;
    Sprite rabbitSprt; // rabbit sprite
    Texture rabbitTxtr;
    Image rabbitImg;
    Sprite wolfMSprt; // male wolf sprite
    Texture wolfMTxtr;
    Image wolfMImg;
    Sprite wolfWSprt; // female wolf sprite
    Texture wolfWTxtr;
    Image wolfWImg;
    Sprite menuSprt; // menu sprite
    Texture menuTxtr;
    Image menuImg;
    Sprite countersSprt[10]; // digits sprite
    Texture countersTxtr[10];
    Image countersImg[10];

//buttons and labels initialization
    tgui::Button::Ptr pTgBtnPlayStep;
    tgui::Button::Ptr pTgBtnPlayAuto;
    tgui::Button::Ptr pTgBtnReset;
    tgui::Label::Ptr LabelMenu;
    tgui::Label::Ptr LabelIndicators;
    tgui::Label::Ptr LabelRabbit;
    tgui::Label::Ptr LabelWolf_W;
    tgui::Label::Ptr LabelWolf_M;
    tgui::Label::Ptr LabelFences;
    tgui::Label::Ptr LabelCurrentStep;

//sets labels and buttons to the menu and fills it with textures
    void initMenu();
    void initFieldTextures();

//draws all simulation window
    void drawMap();
    void drawMenu();
    void drawAnimals();
};

#endif //CPP_GUIVIEW_H
