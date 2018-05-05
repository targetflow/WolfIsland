//
// Created by Alex Orlovskyi on 05.05.18.
//

#ifndef WOLF_ISLAND_CONSOLE_GAME_BASEVIEW_H
#define WOLF_ISLAND_CONSOLE_GAME_BASEVIEW_H

class BaseView {
 public:
    virtual ~BaseView(){}
    virtual void displayField() = 0;
 protected:
    BaseView(){}
};
#endif //WOLF_ISLAND_CONSOLE_GAME_BASEVIEW_H
