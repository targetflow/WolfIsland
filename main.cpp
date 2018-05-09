//
// Created by katya on 04/04/18.
//

#include "controller/Controller.h"
#include "view/menu.h"

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
        RenderWindow window(sf::VideoMode(896, 640), windowTitle);
        window.setFramerateLimit(FPS); // без цього комп іде на взрив, проц ппц

        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, &window);

        Time delayTime = sf::seconds(1); // без цієї затримки натиснення клавіші побуджує більше ніж 1 виклик.
CircleShape PlayRect(50);
PlayRect.setPosition(Vector2f(730,64));
CircleShape AutoPlay(50);
AutoPlay.setPosition(730, 256);
window.draw(PlayRect);
        while (window.isOpen()) {
            window.draw(PlayRect);
            window.draw(AutoPlay);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // transform the mouse position from window coordinates to world coordinates
                sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                sf::FloatRect boundAuto = AutoPlay.getGlobalBounds();
                // retrieve the bounding box of the sprite
                sf::FloatRect boundPlay = PlayRect.getGlobalBounds();

                // hit test
                if (boundPlay.contains(mouse))
                {
                    sf::sleep(delayTime);
                    controller.execute(1);
                }
                if(boundAuto.contains(mouse))
                {
                    Event event;
                    while (window.pollEvent(event)) {
                        if(event.key.code == sf::Keyboard::Return){
                            keepExecuting = true;
                        }
                        if(event.key.code == sf::Keyboard::Escape){
                            window.close();
                        }
                        if (keepExecuting) {  // якщо вмикач увімкнено, "подавай світло" (допоки вмикач не буде вимкнено)
                            sf::sleep(delayTime);
                            controller.execute(1);// робить рух можливим
                        }
//                        window.display();


                }}}
//                    if(event.key.code == sf::Keyboard::Escape){
//                        keepExecuting = false;
//                    }
//                    keepExecuting = true;
//                    if (keepExecuting) {  // якщо вмикач увімкнено, "подавай світло" (допоки вмикач не буде вимкнено)
//                            sf::sleep(delayTime);
//                            controller.execute(1);// робить рух можливим
//                        }
//                    if(event.key.code == sf::Keyboard::Escape){
//                        keepExecuting = false;
//                    }


            sf::Event event {};
//            while (window.pollEvent(event)) {
////                sf::IntRect PLayStepButtonRect(704, 64, 160, 64);
////                if (PlayRect.intersects(PLayStepButtonRect) && event.type == sf::Event::MouseButtonPressed)
//                switch (event.type) {
//                    case sf::Event::KeyReleased:
//                        if (event.key.code == sf::Keyboard::Right) { //step-by-step
//                            keepExecuting = false;
//                            sf::sleep(delayTime);
//                            controller.execute(1);
//                        } else if (event.key.code == sf::Keyboard::Left) { // start/continue
//                            keepExecuting = !keepExecuting;
//                        } else if (event.key.code == sf::Keyboard::Down) // stop/pause
//                            keepExecuting = false;
//                        break;
//                    case sf::Event::Closed:
//                        window.close();
//                        break;
//                    default:
//                        break;
//                }
//            }

//            if (keepExecuting) {  // якщо вмикач увімкнено, "подавай світло" (допоки вмикач не буде вимкнено)
//                sf::sleep(delayTime);
//                controller.execute(1);// робить рух можливим
//            }
            //window.clear();
            window.display();
        }
    } else { // console mode
        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, nullptr);
        controller.execute(countOfSteps);
    }

}


//    if (useGUI) {
//        // SFML Program starts here
//        RenderWindow window(sf::VideoMode(640, 640), "menu");
////        RenderWindow window1(sf::VideoMode(640, 640), "lel");
//        Menu menu(window.getSize().x, window.getSize().y);
//        window.setFramerateLimit(FPS); // без цього комп іде на взрив, проц ппц
//
//        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, &window);
//
//        Time delayTime = sf::seconds(1); // без цієї затримки натиснення клавіші побуджує більше ніж 1 виклик.
//
//        while (window.isOpen()) {
//            sf::Event event;
//
//            while (window.pollEvent(event)) {
//                switch (event.type) {
//                    case sf::Event::KeyReleased:
//                        switch (event.key.code) {
//                            case sf::Keyboard::Up:
//                                menu.MoveUp();
//                                break;
//
//                            case sf::Keyboard::Down:
//                                menu.MoveDown();
//                                break;
//
//
//                            case sf::Keyboard::Return:
//                                switch (menu.GetPressedItem()) {
//                                    case 0: {
//                                        RenderWindow window1(sf::VideoMode(640, 640), windowTitle);
//                                        window1.setFramerateLimit(FPS);
//                                        while (window1.isOpen()) {
//                                            sf::Event event;
//
//                                            while (window1.pollEvent(event)) {
//                                                if (event.type == sf::Event::Closed)
//                                                    window1.close();
//
//                                            }
//
//                                        if (Keyboard::isKeyPressed(Keyboard::Left)) {
//                                            controller.execute(1);
//                                            sf::sleep(delayTime);
//                                            window.clear();
//                                            window1.display();
//
////                                            window1.display();
//                                        }
////                                        window.clear();
////                                        window1.display();
//                                        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
//                                            window1.close();
//                                        }
//                                            window.clear();
//                                            window1.display();
//
//                                }
//                                        break;  }
//                                    case 1:
//                                        std::cout << "tratata" << std::endl;
//                                        break;
//                                    case 2:
//                                        window.close();
//                                        break;
//                                }
//                                window.display();
//
//                                break;
//
//                        }
//
//                        break;
//                    case sf::Event::Closed:
//                        window.close();
//
//                        break;
//
//                }
//            }
//
//            window.clear();
//
//            menu.draw(window);
//
//            window.display();
//        }
//    }}
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                switch (event.type) {
//                    case sf::Event::KeyReleased:
//                        if (event.key.code == sf::Keyboard::Right) { //step-by-step
//                            keepExecuting = false;
//                            sf::sleep(delayTime);
//                            controller.execute(1);
//                        } else if (event.key.code == sf::Keyboard::Left) { // start/continue
//                            keepExecuting = !keepExecuting;
//                        } else if (event.key.code == sf::Keyboard::Down) // stop/pause
//                            keepExecuting = false;
//                        break;
//                    case sf::Event::Closed:
//                        window.close();
//                        break;
//                    default:
//                        break;
//                }


//            if (keepExecuting) {  // якщо вмикач увімкнено, "подавай світло" (допоки вмикач не буде вимкнено)
//                sf::sleep(delayTime);
//                controller.execute(1);// робить рух можливим
//            }
//            //window.clear();
//            window.display();
//        }
//    } else { // console mode
//        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, nullptr);
//        controller.execute(countOfSteps);
//    }
//
//}

