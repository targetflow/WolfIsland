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

#include "GUIView.h"

GUIView::GUIView(Field *_pField, RenderWindow *_pWindow, tgui::Gui *_pTGUI) {
    this->pField = _pField;
    this->pWindow = _pWindow;
    this->pTGUI = _pTGUI;

    initFieldTextures();
    initMenu();
}

GUIView::~GUIView() = default;

void GUIView::displayField() {
    drawMap();
    drawMenu();
    drawAnimals();
}

void GUIView::initMenu() {
    // you can choose fonts here: https://www.fontsquirrel.com/fonts/list/popular
    // or here: https://www.1001freefonts.com/
    // font for general lables
    labelsFont.loadFromFile("../resources/fonts/open-sans/OpenSans-Semibold.ttf");

    // menu textures
    menuImg.loadFromFile("../resources/textures/menu/tile_black.png");
    menuTxtr.loadFromImage(menuImg);
    menuSprt.setTexture(menuTxtr);

    // TGUI menu buttons
    // Perform next step button
    pTgBtnPlayStep = tgui::Button::create();
    pTgBtnPlayStep->setText(L"Step");
    pTgBtnPlayStep->setTextSize(15);
    pTgBtnPlayStep->setSize(Vector2f(180, 50));
    pTgBtnPlayStep->setPosition(Vector2f(680, 55));
    pTGUI->add(pTgBtnPlayStep, "PlayStep");

    //Perform auto button
    pTgBtnPlayAuto = tgui::Button::create();
    pTgBtnPlayAuto->setText(L"Auto simulation");
    pTgBtnPlayAuto->setTextSize(15);
    pTgBtnPlayAuto->setSize(Vector2f(180, 50));
    pTgBtnPlayAuto->setPosition(Vector2f(680, 117));
    pTGUI->add(pTgBtnPlayAuto, "PlayAuto");

    //Perform reset button
    pTgBtnReset = tgui::Button::create();
    pTgBtnReset->setText(L"Reset simulation");
    pTgBtnReset->setTextSize(15);
    pTgBtnReset->setSize(Vector2f(180, 50));
    pTgBtnReset->setPosition(Vector2f(680, 179));
    pTGUI->add(pTgBtnReset, "ResetSimulation");

    // TGUI labels
    // menu
    LabelMenu = tgui::Label::create();
    LabelMenu->setPosition(743, 20);
    LabelMenu->setText(L"Menu");
    LabelMenu->setTextColor(sf::Color::Yellow);
    LabelMenu->setTextStyle(sf::Text::Underlined);
    LabelMenu->setFont(labelsFont);
    LabelMenu->setTextSize(16);
    pTGUI->add(LabelMenu, "labelMenu");

    // indicators
    LabelIndicators = tgui::Label::create();
    LabelIndicators->setPosition(725, 250);
    LabelIndicators->setText(L"Indicators");
    LabelIndicators->setTextColor(sf::Color::Yellow);
    LabelIndicators->setTextStyle(sf::Text::Underlined);
    LabelIndicators->setFont(labelsFont);
    LabelIndicators->setTextSize(16);
    pTGUI->add(LabelIndicators, "labelIndicators");

    //display current step
    LabelCurrentStep = tgui::Label::create();
    LabelCurrentStep->setPosition(653, 280);
    LabelCurrentStep->setTextColor(sf::Color::White);
    LabelCurrentStep->setTextSize(16);
    pTGUI->add(LabelCurrentStep, "labelCurrentStep");

    //display count of rabbits
    LabelRabbit = tgui::Label::create();
    LabelRabbit->setPosition(653, 305);
    LabelRabbit->setTextColor(sf::Color::White);
    LabelRabbit->setTextSize(16);
    pTGUI->add(LabelRabbit, "labelRabbits");

    //display count of Wolf_W
    LabelWolf_W = tgui::Label::create();
    LabelWolf_W->setPosition(653, 330);
    LabelWolf_W->setTextColor(sf::Color::White);
    LabelWolf_W->setTextSize(16);
    pTGUI->add(LabelWolf_W, "labelWolf_W");

    //display count of Wolf_M
    LabelWolf_M = tgui::Label::create();
    LabelWolf_M->setPosition(653, 355);
    LabelWolf_M->setTextColor(sf::Color::White);
    LabelWolf_M->setTextSize(16);
    pTGUI->add(LabelWolf_M, "labelWolf_M");

    //display count of Fences
    LabelFences = tgui::Label::create();
    LabelFences->setPosition(653, 380);
    LabelFences->setTextColor(sf::Color::White);
    LabelFences->setTextSize(16);
    pTGUI->add(LabelFences, "labelFences");
}


void GUIView::initFieldTextures() {
    // Top textures src: https://openclipart.org/search/
    // Display:
    // grass
    grassImg.loadFromFile("../resources/textures/grass/orig/grass00.png"); //завантажуємо файл для карти
    grassTxtr.loadFromImage(grassImg); //заряжаємо текстуру зображенням
    grassSprt.setTexture(grassTxtr); //заливаємо текстуру спрайтом

    // fence (textures src: https://pngtree.com/so/fence)
    fenceImg.loadFromFile("../resources/textures/fence/processed/fence30x16.png");
    fenceTxtr.loadFromImage(fenceImg);
    fenceSprt.setTexture(fenceTxtr);

    // rabbit
    // texture variants:
    // https://openclipart.org/detail/190731/chinese-zodiac-rabbit
    rabbitImg.loadFromFile("../resources/textures/rabbit/processed/chinese-zodiac-rabbit-color-16x15.png"); // top 1
    // https://openclipart.org/detail/252511/pink-rabbit
    // rabbitImg.loadFromFile("../resources/textures/rabbit/processed/rabbit-pink-16x16.png");
    // https://openclipart.org/detail/295161/pink-rabbit
    // rabbitImg.loadFromFile("../resources/textures/rabbit/processed/FX13_rabbit3-pink-16x14.png");
    // https://openclipart.org/detail/293944/rabbit - коричневий, нормас
    // rabbitImg.loadFromFile("../resources/textures/rabbit/processed/FX13_rabbit-15x16.png");
    rabbitTxtr.loadFromImage(rabbitImg);
    rabbitSprt.setTexture(rabbitTxtr);

    // wolfM
    // texture variants:
    // wolfMImg.loadFromFile("../resources/textures/WolfM/processed/Howling-Wolf-Silhouette-16x16.png"); // теж норм вовк
    // wolfMImg.loadFromFile("../resources/textures/WolfM/processed/doushouqi-wolf-16x16.png"); // так собі видно
    wolfMImg.loadFromFile("../resources/textures/WolfM/processed/wolf16x17.png"); // наш старий вовк, непогано видно.
    wolfMTxtr.loadFromImage(wolfMImg);
    wolfMSprt.setTexture(wolfMTxtr);

    // wolfW
    // texture variants:
    // райдужна - так собі видно:
    // wolfWImg.loadFromFile("../resources/textures/WolfW/processed/Multispectral-Gem-Howling-Wolf-16x17.png");

    // "вою на луну" - взагалі не видно
    // wolfWImg.loadFromFile("../resources/textures/WolfW/processed/Crescent-Moon-Wolf-16x17.png");

    // так собі, сіре на зеленому не дуже
    // wolfWImg.loadFromFile("../resources/textures/WolfW/processed/dibujo-26-16x17.png");
    wolfWImg.loadFromFile("../resources/textures/WolfW/processed/blankwolfhead2-16x17.png");
    wolfWTxtr.loadFromImage(wolfWImg);
    wolfWSprt.setTexture(wolfWTxtr);

    // numbers
    // https://openclipart.org/detail/227860/coloring-page-pi-day-digits-of-pi-large
    std::string pathToNumbersImgs;
    std::string baseNumbersImgPath = "../resources/textures/numbers/processed/";
    for (unsigned int i = 0; i < 9; i ++) {
        pathToNumbersImgs = "";
        pathToNumbersImgs += baseNumbersImgPath;
        pathToNumbersImgs += "red/";
        pathToNumbersImgs += std::to_string(i+1);
        pathToNumbersImgs += ".png";

        countersImg[i].loadFromFile(pathToNumbersImgs);
        countersTxtr[i].loadFromImage(countersImg[i]);
        countersSprt[i].setTexture(countersTxtr[i]);
    }

    // add "+" sprite for displaying more then 9 animals
    countersImg[9].loadFromFile(baseNumbersImgPath + "red/plus.png");
    countersTxtr[9].loadFromImage(countersImg[9]);
    countersSprt[9].setTexture(countersTxtr[9]);
}

void GUIView::drawMap() {
    // draw grass
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++) {
            if (TileMap[i][j] == '0') {
                grassSprt.setTextureRect(IntRect(0, 0, 32, 32));
                grassSprt.setPosition(j * 32, i * 32); //place textures on the map,
                                                       //setting a specific position for each of them
                pWindow->draw(grassSprt);
            }
        }

    // draw fences
    for (int i = 0; i < 400; i++) {
        if (pField->getCells()->at(static_cast<unsigned long>(i)).isFence()) {
            fenceSprt.setTextureRect(IntRect(0, 0, 30, 16));
            fenceSprt.setPosition((i%20) * 32, (i/20) * 32 + 7); // +7 - in order for the fence to be in the center
                                                                 // of the cell.
            pWindow->draw(fenceSprt);
        }
    }
}

void GUIView::drawMenu() {
    // draw menu textures
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++) {
            if (TileMap[i][j] == '1') {
                menuSprt.setTextureRect(IntRect(0, 0, 32, 32));
                menuSprt.setPosition(j * 32, i * 32);
                pWindow->draw(menuSprt);
            } // draw sprite in specific position
        }
}

void GUIView::drawAnimals() {
    int countOfRabbits, countOfWolvesW, countOfWolvesM;
    unsigned int index;
    for (int i = 0; i < 400; i++) {
        // draw rabbits
        if (!pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->empty()) {
            countOfRabbits =
                static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->size());
            index = static_cast<unsigned int>(countOfRabbits-1);
            for (int j = 0; j < countOfRabbits; j++) {
                rabbitSprt.setTextureRect(IntRect(0, 0, 16, 16));
                rabbitSprt.setPosition((i%20) * 32, (i/20) * 32); // +7 - in order for the fence to be in the center
                                                                  // of the cell.
                pWindow->draw(rabbitSprt);
            }

            // draw count
            index = static_cast<unsigned int>(countOfRabbits-1);
            if (index > 9)
                index = 9; // when there are more then 9 animals of specific type in the cell - always show "+" sprite.
            countersSprt[index].setTextureRect(IntRect(0, 0, 8, 8));
            countersSprt[index].setPosition((i%20) * 32 + 16, (i/20) * 32);
            pWindow->draw(countersSprt[index]);
        }

        // draw female wolf
        if (!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->empty()) {
            countOfWolvesW =
                static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->size());
            for (int j = 0; j < countOfWolvesW; j++) {
                wolfWSprt.setTextureRect(IntRect(0, 0, 16, 16));
                wolfWSprt.setPosition((i%20) * 32 + 16, (i/20) * 32 + 16);
                pWindow->draw(wolfWSprt);
            }

            // draw count
            index = static_cast<unsigned int>(countOfWolvesW-1);
            if (index > 9)
                index = 9; // when there are more then 9 animals of specific type in the cell - always show "+" sprite.
            countersSprt[index].setTextureRect(IntRect(0, 0, 8, 8));
            countersSprt[index].setPosition((i%20) * 32 + 24, (i/20) * 32 + 8);
            pWindow->draw(countersSprt[index]);
        }

        // draw male wolf
        if (!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->empty()) {
            countOfWolvesM =
                static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->size());
            for (int j = 0; j < countOfWolvesM; j++) {
                wolfMSprt.setTextureRect(IntRect(0, 0, 16, 16));
                wolfMSprt.setPosition((i%20) * 32, (i/20) * 32 + 16);
                pWindow->draw(wolfMSprt);
            }

            // draw count
            index = static_cast<unsigned int>(countOfWolvesM-1);
            if (index > 9)
                index = 9; // when there are more then 9 animals of specific type in the cell - always show "+" sprite.
            countersSprt[index].setTextureRect(IntRect(0, 0, 8, 8));
            countersSprt[index].setPosition((i%20) * 32 + 16, (i/20) * 32 + 8);
            pWindow->draw(countersSprt[index]);
        }
    }
}
