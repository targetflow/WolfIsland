//
// Created by katya on 08/05/18.
//

#ifndef WOLF_ISLAND_CONSOLE_GAME_MENU_H
#define WOLF_ISLAND_CONSOLE_GAME_MENU_H


#include "SFML/Graphics.hpp"
using namespace sf;


#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

#endif //WOLF_ISLAND_CONSOLE_GAME_MENU_H
