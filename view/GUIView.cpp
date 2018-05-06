//
// Created by Alex Orlovskyi on 05.05.18.
//

#include "GUIView.h"

GUIView::GUIView(Field *_pField, RenderWindow *_pWindow) {
    this->pField = _pField;
    this->pWindow = _pWindow;

    // Топ текстури: https://openclipart.org/search/
    // Ініціалізація відображення:
    // трави на карті
    grassImg.loadFromFile("../resources/textures/grass/orig/grass00.png"); //завантажуємо файл для карти
    grassTxtr.loadFromImage(grassImg); //заряжаємо текстуру зображенням
    grassSprt.setTexture(grassTxtr); //заливаємо текстуру спрайтом

    // огорожі (текстури: https://pngtree.com/so/fence)
    fenceImg.loadFromFile("../resources/textures/fence/processed/fence30x16.png");
    fenceTxtr.loadFromImage(fenceImg);
    fenceSprt.setTexture(fenceTxtr);

    // кроля
    // Варіанти текстур:
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
}

GUIView::~GUIView() = default;

void GUIView::displayField() {
    drawMap();

    int countOfRabbits, countOfWolvesW, countOfWolvesM;
    for (int i = 0; i < 400; i++) {
        if (!pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->empty()) {
            countOfRabbits =
                static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getRabbits()->size());
            for (int j = 0; j < countOfRabbits; j++) {
                rabbitSprt.setTextureRect(IntRect(0, 0, 16, 15));
                rabbitSprt.setPosition((i%20) * 32, (i/20) * 32); // +7 - щоб огорожа була по центру клітинки.
                // а от чи правильно обчислює позиції - на 100% не впевнений. Варто ще далі дослідити, протестувати.
                // 41 = [1][2]
                pWindow->draw(rabbitSprt);
            }
        }
        if (!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->empty()) {
            countOfWolvesW =
                static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_W()->size());
            for (int j = 0; j < countOfWolvesW; j++) {
                //cellContent += "W";
            }
        }
        if (!pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->empty()) {
            countOfWolvesM =
                static_cast<int>(pField->getCells()->at(static_cast<unsigned long>(i)).getWolf_M()->size());
            for (int j = 0; j < countOfWolvesM; j++) {
                //cellContent += "M";
            }
        }
    }
}

void GUIView::drawMap() {
    // draw grass
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            if (TileMap[i][j] == '0')
                grassSprt.setTextureRect(IntRect(0, 0, 32, 32));
            grassSprt.setPosition(j * 32, i * 32); //по сути раскидывает квадратики, превращая в карту. то есть задает
            // каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один
            // квадрат
            pWindow->draw(grassSprt); // виводимо спрайт на екран в поточній заданій позиції (задається вище ^ ^)
        }

    // draw fences
    for (int i = 0; i < 400; i++) {
        if (pField->getCells()->at(static_cast<unsigned long>(i)).isFence()) {
            fenceSprt.setTextureRect(IntRect(0, 0, 30, 16));
            fenceSprt.setPosition((i%20) * 32, (i/20) * 32 + 7); // +7 - щоб огорожа була по центру клітинки.
            // а от чи правильно обчислює позиції - на 100% не впевнений. Варто ще далі дослідити, протестувати.
            // 41 = [1][2]
            pWindow->draw(fenceSprt);
        }
    }
}

