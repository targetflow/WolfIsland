//
// Created by katya on 04/04/18.
//

#include "controller/Controller.h"
#include "view/map.h"

int main(){
    const int nRabbits = 12;
    const int nMWolves = 4;
    const int nWWolves = 3;
    const int cOfFences = 5;
    const int countOfSteps = 3;
    //const bool useGUI = false;
    const bool useGUI = true;



    if (useGUI) {
        // SFML Program starts here
        RenderWindow window(sf::VideoMode(640, 640), "Wolves Island simulation");
        window.setFramerateLimit(60); // без цього комп іде на взрив, проц ппц

        Image map_image;//объект изображения для карты
        map_image.loadFromFile("../resources/grass00.png");//загружаем файл для карты
        Texture map;//текстура карты
        map.loadFromImage(map_image);//заряжаем текстуру картинкой
        Sprite s_map;//создаём спрайт для карты
        s_map.setTexture(map);//заливаем текстуру спрайтом

        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, useGUI);

        Time delayTime = sf::seconds(1); // без цієї затримки натиснення клавіші побуджує більше ніж 1 виклик.

        while (window.isOpen())
        {
            sf::Event event {};
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if ((Keyboard::isKeyPressed(Keyboard::Left))) {
                controller.execute(1);
                sf::sleep(delayTime);
            }

            window.clear();
            //малюєм карту
            for (int i = 0; i < HEIGHT_MAP; i++)
                for (int j = 0; j < WIDTH_MAP; j++)
                {
                    if((TileMap[i][j] == '0') ) s_map.setTextureRect(IntRect(0, 0, 32, 32));
                    s_map.setPosition(j * 32, i * 32); //по сути раскидывает квадратики, превращая в карту. то есть задает
                    // каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один
                    // квадрат
                    window.draw(s_map); //рисуем квадратики на экран
                }
            window.display();
        }
    } else {
        // console mode
        Controller controller(nRabbits, nMWolves, nWWolves, cOfFences, useGUI);
        controller.execute(countOfSteps);
    }


    // test2
//    std::vector<int> a;
//    std::vector<int> b;
//    a.emplace_back(1);
//    a.emplace_back(2);
//    a.emplace_back(3);
//    b.emplace_back(4);
//    b.emplace_back(5);
//    b.emplace_back(6);
//    for (int &i : a)
//        std::cout << i << ' ';
//    std::cout << std::endl;
//    for (int &i : b)
//        std::cout << i << ' ';
//    std::cout << "New next" << std::endl;
//    a.insert(a.end(), std::make_move_iterator(b.begin()), std::make_move_iterator(b.begin()+1));
//    b.erase(b.begin(), b.begin()+1);
//    for (int &i : a)
//        std::cout << i << ' ';
//    std::cout << std::endl;
//    for (int &i : b)
//        std::cout << i << ' ';
    // test
//    std::vector<int> testVec;
//    testVec = controller.makeListOfAvailableStepsForRabbit(399);
//    for (int &i : testVec)
//        std::cout << i << ' ';

//srand(time(NULL));
//long i = random()%5;
////std::cout<<i;
//    std::vector<int> myvector;
//    myvector.push_back (100);
//    myvector.push_back (200);
//    myvector.push_back (300);
//    int sie = static_cast<int>(myvector.size());
//    std::cout<<sie<<std::endl;
//    for (int i=0;i<myvector.size(); i++)
//    std::cout<<myvector[i]<<std::endl;
//    myvector.pop_back();
//    for (int i=0;i<myvector.size(); i++)
//        std::cout<<myvector[i]<<std::endl;

}

