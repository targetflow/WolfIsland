//
// Created by katya on 08/05/18.
//

#include "menu.h"

//fill menu items with text, color, font and set needed position
Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("/home/katya/Downloads/ARIAL.TTF"))
    {
        //error;
    }
    //fill and set "Play step-by-step" button
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::White);
    menu[0].setString("Play step-by-step");
    menu[0].setPosition(sf::Vector2f(width / 7, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    //fill and set "Play automate" button
    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Play automate");
    menu[1].setPosition(sf::Vector2f(width / 7, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    //fill and set "Instructions" button
    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Instructions");
    menu[2].setPosition(sf::Vector2f(width / 7, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}


Menu::~Menu()
{
}

//draws all menu items
void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

//changes selected item color to white
void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

//changes selected item color to white
void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}