//
// Created by katya on 04/04/18.
//

#include "controller/Controller.h"

int main() {
    String windowTitle = "Wolves Island simulation";
    const int nRabbits = 12;
    const int nMWolves = 4;
    const int nWWolves = 3;
    const int cOfFences = 5;
    const int countOfSteps = 3;
    const bool useGUI = true;
    const int FPS = 60;

    Time delayTime = seconds(1);

    bool keepExecuting = false;
    if (useGUI) {
        // SFML Program starts here
        RenderWindow window(VideoMode(896, 640), windowTitle);
        window.setFramerateLimit(FPS); // без цього комп іде на взрив, проц ппц

        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, &window);

        FloatRect boundPlay = controller.getPGUIView()->getBtnPlayStep()->getGlobalBounds();
        FloatRect boundAuto = controller.getPGUIView()->getSwitchAutoPlayOrPause()->getGlobalBounds();

        while (window.isOpen()) {
            Event event {};
            while (window.pollEvent(event)) {
                if (event.type == Event::MouseButtonReleased) {
                    if (event.mouseButton.button == Mouse::Left) {
                        Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));

                        if (boundPlay.contains(mouse)) { //step game
                            sleep(delayTime);
                            controller.execute(1);
                            keepExecuting = false;
                        } else if (boundAuto.contains(mouse)) { //automate start/continue
                            keepExecuting = !keepExecuting;
                        }
                    }
                }

                window.display();
            }

            if (keepExecuting) { // якщо вмикач увімкнено, "подавай світло" (допоки вмикач не буде вимкнено)
                sleep(delayTime);
                controller.execute(1);
            }

            window.display();
        }
    } else { // console mode
        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, nullptr);
        controller.execute(countOfSteps);
    }
}


