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

        while (window.isOpen()) {
            sf::Event event {};
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::KeyReleased:
                        if (event.key.code == sf::Keyboard::Right) { //step-by-step
                            keepExecuting = false;
                            sf::sleep(delayTime);
                            controller.execute(1);
                        } else if (event.key.code == sf::Keyboard::Left) { // start/continue
                            keepExecuting = !keepExecuting;
                        } else if (event.key.code == sf::Keyboard::Down) // stop/pause
                            keepExecuting = false;
                        break;
                    case sf::Event::Closed:
                        window.close();
                        break;
                    default:
                        break;
                }
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

