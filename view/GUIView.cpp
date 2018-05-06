//
// Created by Alex Orlovskyi on 05.05.18.
//

#include "GUIView.h"

GUIView::GUIView(Field *_pField, RenderWindow *_pWindow) {
    this->pField = _pField;
    this->pWindow = _pWindow;

    // Ініціалізація карти
    grassImg.loadFromFile("../resources/grass00.png"); //завантажуємо файл для карти
    grassTxtr.loadFromImage(grassImg); //заряжаємо текстуру зображенням
    grassSprt.setTexture(grassTxtr); //заливаємо текстуру спрайтом
}

GUIView::~GUIView() = default;

void GUIView::displayField() {
    drawMap();
}

void GUIView::drawMap() {
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
}

