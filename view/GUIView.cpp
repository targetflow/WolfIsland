//
// Created by Alex Orlovskyi on 05.05.18.
//

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
    // menu textures
    menuImg.loadFromFile("../resources/textures/menu/tile_black.png");
    menuTxtr.loadFromImage(menuImg);
    menuSprt.setTexture(menuTxtr);

    // TGUI menu buttons
    // Perform next step button
    pTgBtnPlayStep = tgui::Button::create();
    pTgBtnPlayStep->setText("Perform 1 move");
    pTgBtnPlayStep->setTextSize(16);
    pTgBtnPlayStep->setSize(Vector2f(160,50));
    pTgBtnPlayStep->setPosition(Vector2f(690,80));
    pTGUI->add(pTgBtnPlayStep, "PlayStep");

    //Perform auto button
    pTgBtnPlayAuto = tgui::Button::create();
    pTgBtnPlayAuto->setText("Auto play");
    pTgBtnPlayAuto->setTextSize(16);
    pTgBtnPlayAuto->setSize(Vector2f(160,50));
    pTgBtnPlayAuto->setPosition(Vector2f(690,142));
    pTGUI->add(pTgBtnPlayAuto, "PlayAuto");

    //Perform reset button
    pTgBtnReset = tgui::Button::create();
    pTgBtnReset->setText("Reset");
    pTgBtnReset->setTextSize(16);
    pTgBtnReset->setSize(Vector2f(160,50));
    pTgBtnReset->setPosition(Vector2f(690,204));
    pTGUI->add(pTgBtnReset, "Reset");

    //display count of rabbits
    LabelRabbit = tgui::Label::create();
    LabelRabbit->setPosition(648, 300);
    LabelRabbit->setTextColor(sf::Color::White );
    LabelRabbit->setTextSize(18);
    pTGUI->add(LabelRabbit, "labelRabbits");

    //display count of Wolf_W
    LabelWolf_W = tgui::Label::create();
    LabelWolf_W->setPosition(648, 364);
    LabelWolf_W->setTextColor(sf::Color::White );
    LabelWolf_W->setTextSize(18);
    pTGUI->add(LabelWolf_W, "labelWolf_W");

    //display count of Wolf_M
    LabelWolf_M = tgui::Label::create();
    LabelWolf_M->setPosition(648, 428);
    LabelWolf_M->setTextColor(sf::Color::White );
    LabelWolf_M->setTextSize(18);
    pTGUI->add(LabelWolf_M, "labelWolf_M");

    //display count of Fences
    LabelFences = tgui::Label::create();
    LabelFences->setPosition(648, 492);
    LabelFences->setTextColor(sf::Color::White );
    LabelFences->setTextSize(18);
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
    // wolfWImg.loadFromFile("../resources/textures/WolfW/processed/Multispectral-Gem-Howling-Wolf-16x17.png"); // райдужна - так собі видно
    // wolfWImg.loadFromFile("../resources/textures/WolfW/processed/Crescent-Moon-Wolf-16x17.png"); // "вою на луну" - взагалі не видно
    // wolfWImg.loadFromFile("../resources/textures/WolfW/processed/dibujo-26-16x17.png"); // так собі, сіре на зеленому не дуже
    wolfWImg.loadFromFile("../resources/textures/WolfW/processed/blankwolfhead2-16x17.png");
    wolfWTxtr.loadFromImage(wolfWImg);
    wolfWSprt.setTexture(wolfWTxtr);
}

void GUIView::drawMap() {
    // draw grass
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++) {
            if (TileMap[i][j] == '0') {
                grassSprt.setTextureRect(IntRect(0, 0, 32, 32));
                grassSprt.setPosition(j * 32, i * 32); // розміщуємо текстури по карті, задаючи конкретну позицію кожній з
                // них. Якщо без цього, то вся карта буде складатись лиш з одного квадрата 32*32.
                pWindow->draw(grassSprt);
            }
        }

    // draw fences
    for (int i = 0; i < 400; i++) {
        if (pField->getCells()->at(static_cast<unsigned long>(i)).isFence()) {
            fenceSprt.setTextureRect(IntRect(0, 0, 30, 16));
            fenceSprt.setPosition((i%20) * 32, (i/20) * 32 + 7); // +7 - щоб огорожа була по центру клітинки.
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
            } // виводимо спрайт на екран в поточній заданій позиції (задається вище ^ ^)
        }

    // draw menu "buttons"

}

void GUIView::drawAnimals() {
    int countOfRabbits, countOfWolvesW, countOfWolvesM;
    for (int i = 0; i < 400; i++) {
        // draw rabbits
        if (!pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->empty()) {
            countOfRabbits =
                static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->size());
            for (int j = 0; j < countOfRabbits; j++) {
                rabbitSprt.setTextureRect(IntRect(0, 0, 16, 16));
                rabbitSprt.setPosition((i%20) * 32, (i/20) * 32); // +7 - щоб огорожа була по центру клітинки.
                pWindow->draw(rabbitSprt);
            }
        }

        // draw wolvesW
        if (!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->empty()) {
            countOfWolvesW =
                static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->size());
            for (int j = 0; j < countOfWolvesW; j++) {
                wolfWSprt.setTextureRect(IntRect(0, 0, 16, 16));
                wolfWSprt.setPosition((i%20) * 32 + 16, (i/20) * 32 + 16);
                pWindow->draw(wolfWSprt);
            }
        }

        // draw wolvesM
        if (!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->empty()) {
            countOfWolvesM =
                static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->size());
            for (int j = 0; j < countOfWolvesM; j++) {
                wolfMSprt.setTextureRect(IntRect(0, 0, 16, 16));
                wolfMSprt.setPosition((i%20) * 32, (i/20) * 32 + 16);
                pWindow->draw(wolfMSprt);
            }
        }
    }
}

//RectangleShape *GUIView::getBtnSwitchAutoPlayOrPause() {
//    return &btnSwitchAutoPlayOrPause;
//}

