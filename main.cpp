//
// Created by katya on 04/04/18.
//

#include "controller/Controller.h"

int main(){
    sf::String windowTitle = "Wolves Island simulation";
    const int nRabbits = 12;
    const int nMWolves = 4;
    const int nWWolves = 3;
    const int cOfFences = 5;
    const int countOfSteps = 3;
    const bool useGUI = true;
    const int FPS = 60;

    bool keepExecuting = false;

    if (useGUI) {
        // SFML Program starts here
        RenderWindow window(sf::VideoMode(640, 640), windowTitle);
        window.setFramerateLimit(FPS); // без цього комп іде на взрив, проц ппц

        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, &window);

        Time delayTime = sf::seconds(1); // без цієї затримки натиснення клавіші побуджує більше ніж 1 виклик.
        sf::Clock clock;

        while (window.isOpen())
        {
            sf::Event event {};
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)){
                sf::sleep(delayTime);
                controller.execute(1);
            }

            if ((Keyboard::isKeyPressed(Keyboard::Left))) {
                keepExecuting = !keepExecuting;  // змінити стан вмикача
            }

            if (keepExecuting) {  // якщо вмикач увімкнено, "подавай світло" (допоки вмикач не буде вимкнено)
                sf::sleep(delayTime);
                controller.execute(1);// робить рух можливим
            }
            //window.clear();
            window.display();
        }
    } else { // console mode
        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, nullptr);
        controller.execute(countOfSteps);
    }

}

