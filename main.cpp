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
    const float FPS = 60.0f;

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
            if ((Keyboard::isKeyPressed(Keyboard::Right))){
                if (clock.getElapsedTime().asSeconds() >= 60.0f / FPS)//здійснюєм рух коли ми на 60 кадрі
                {
                    controller.execute(1);
                    clock.restart();
                } else //нічо не робим поки знову не настане 60 кадр із 60-ти за секунду
                {
                    Time sleepTime = seconds((60.0f / FPS) - clock.getElapsedTime().asSeconds());
                    sleep(sleepTime);
                }
            }

            if ((Keyboard::isKeyPressed(Keyboard::Left))) {
                controller.execute(1);// робить рух можливим
                sf::sleep(delayTime);
            }

            window.clear();
            controller.getPView()->displayField(); // draw map // потім це має бути по таймеру
            window.display();
        }
    } else { // console mode
        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, nullptr);
        controller.execute(countOfSteps);
    }

}

