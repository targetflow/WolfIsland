//
// Created by katya on 04/04/18.
//

#include "controller/Controller.h"
using namespace std;

int main() {
    sf::String windowTitle = "Wolves Island simulation";
    const int nRabbits = 12;
    const int nMWolves = 4;
    const int nWWolves = 3;
    const int cOfFences = 5;
    const int countOfSteps = 3;
    const bool useGUI = true;
    const int FPS = 60;
    RectangleShape PlayStep(Vector2f(160,50));
    PlayStep.setPosition(Vector2f(690,80));
    PlayStep.setOutlineThickness(6);
    PlayStep.setOutlineColor(sf::Color::Black );

    RectangleShape AutoPlay(Vector2f(160,50));
    AutoPlay.setPosition(690, 176);
    AutoPlay.setOutlineThickness(6);
    AutoPlay.setOutlineColor(sf::Color::Black );

    RectangleShape Pause(Vector2f(160,50));
    Pause.setPosition(690, 272);
    Pause.setOutlineThickness(6);
    Pause.setOutlineColor(sf::Color::Black);

    RectangleShape Exit(Vector2f(55,55));
    Exit.setPosition(830,10);
    Exit.setFillColor(Color::Red);
    Exit.setOutlineThickness(6);
    Exit.setOutlineColor(sf::Color::Black);

    sf::FloatRect boundAuto = AutoPlay.getGlobalBounds();
    sf::FloatRect boundPlay = PlayStep.getGlobalBounds();
    sf::FloatRect boundPause = Pause.getGlobalBounds();
    sf::FloatRect boundExit = Exit.getGlobalBounds();

    Time delayTime = sf::seconds(1);

    bool keepExecuting = false;
    if (useGUI) {
        // SFML Program starts here
        RenderWindow window(sf::VideoMode(896, 640), windowTitle);
        window.setFramerateLimit(FPS); // без цього комп іде на взрив, проц ппц

        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, &window);

        while (window.isOpen()) {
            sf::Event event {};
            while (window.pollEvent(event)) {
                window.draw(PlayStep);
                window.draw(AutoPlay);
                window.draw(Pause);
                window.draw(Exit);
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                        if (boundPlay.contains(mouse)) { //step game
                            sf::sleep(delayTime);
                            controller.execute(1);
                            keepExecuting = false;
                        } else if (boundAuto.contains(mouse)) { //automate start/continue
                            keepExecuting = !keepExecuting;
                        } else if (boundPause.contains(mouse)) { //pause/stop
                            keepExecuting = false;
                        } else if (boundExit.contains(mouse)) { //pause/stop
                            window.close();
                        }
                    }
                }

                window.display();
            }

            if (keepExecuting) { // якщо вмикач увімкнено, "подавай світло" (допоки вмикач не буде вимкнено)
                sf::sleep(delayTime);
                controller.execute(1);
            }

            window.draw(PlayStep);
            window.draw(AutoPlay);
            window.draw(Pause);
            window.draw(Exit);
            window.display();
        }

    }
    else { // console mode
        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, nullptr);
        controller.execute(countOfSteps);
    }

}


