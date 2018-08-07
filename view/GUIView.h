/**
 * WolfIsland environment modeling project.
 *
 * Copyright 2018 by Kateryna Pereverzeva <katya.pereverzeva2109@gmail.com>
 * Copyright 2018 by Oleksandr Orlovskyi <orlovskyi.alex@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 =========================================================================== */

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
