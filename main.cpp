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
        FloatRect boundAuto = controller.getPGUIView()->getBtnSwitchAutoPlayOrPause()->getGlobalBounds();
        Vector2f mousePosition;

        while (window.isOpen()) {
            Event event {};
            while (window.pollEvent(event)) {
                switch (event.type) {
                    // left mouse button released
                    case Event::MouseButtonReleased:
                        if (event.mouseButton.button == Mouse::Left) {
                            mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));

                            if (boundPlay.contains(mousePosition)) { //step game
                                //sleep(delayTime);
                                controller.execute(1);
                                keepExecuting = false;
                            } else if (boundAuto.contains(mousePosition)) { //automate start/continue
                                keepExecuting = !keepExecuting;
                            }
                        }
                        break;

                    // window resized:
                    case Event::Resized:
                        controller.getPGUIView()->displayField();
                        break;

                    // window closed
                    case Event::Closed:
                        window.close();
                        break;

                    // we don't process other types of events
                    default:
                        break;
                }
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


