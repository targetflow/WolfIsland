//
// Created by Alex Orlovskyi on 21.04.18.
//

#include "Controller.h"

Controller::Controller() {
    this->field = Field();
    initSimulationParams();
    initView();
    initField(nRabbits, nWWolves, nMWolves, cOfFences);
}

Controller::~Controller() {
    delete pView;
}

void Controller::execute() {
    bool keepExecuting = false;
    if (useGUI) {

        TGUI.get("PlayStep")->connect("clicked", &Controller::nextStep, this);
        TGUI.get("PlayAuto")->connect("clicked", [&keepExecuting](bool){ keepExecuting = !keepExecuting;}, keepExecuting);
        TGUI.get("Reset")->connect("clicked", &Controller::restartField, this);
        while (window.isOpen()) {
            Event event {};
            while (window.pollEvent(event)) {
                switch (event.type) {

                    // window resized:
                    case Event::Resized:
                        getPGUIView()->displayField();
                        break;

                    // window closed
                    case Event::Closed:
                        window.close();
                        break;

                    // we don't process other types of events
                    default:
                        break;
                }

                TGUI.handleEvent(event); // Pass the event to the widgets
            }

            if (keepExecuting) { // якщо вмикач увімкнено, "подавай світло" (допоки вмикач не буде вимкнено)
                sleep(delayTimeInSeconds);
                nextStep();
                tgui::Button::Ptr button_auto = TGUI.get<tgui::Button>("PlayAuto");
                button_auto->setText("Pause");
                tgui::Button::Ptr button_step = TGUI.get<tgui::Button>("PlayStep");
                tgui::Button::Ptr button_reset = TGUI.get<tgui::Button>("Reset");
                button_step->disable();
                button_reset->disable();

            }
            if (!keepExecuting) {
                tgui::Button::Ptr button_auto = TGUI.get<tgui::Button>("PlayAuto");
                button_auto->setText("Play auto");
                tgui::Button::Ptr button_step = TGUI.get<tgui::Button>("PlayStep");
                tgui::Button::Ptr button_reset = TGUI.get<tgui::Button>("Reset");
                button_step->enable();
                button_reset->enable();
            }
            std::string rabbit;
            rabbit = std::to_string(countOfRabbits());
            tgui::Label::Ptr labelRabbit = TGUI.get<tgui::Label>("labelRabbits");
            labelRabbit->setText("current count of rabbits: "+rabbit);
            labelRabbit->disable();

            std::string wolf_w;
            wolf_w = std::to_string(countOfWolf_W());
            tgui::Label::Ptr labelWolf_W = TGUI.get<tgui::Label>("labelWolf_W");
            labelWolf_W->setText("current count of wolfess: "+wolf_w);
            labelWolf_W->disable();

            std::string wolf_m;
            wolf_m = std::to_string(countOfWolf_M());
            tgui::Label::Ptr labelWolf_M = TGUI.get<tgui::Label>("labelWolf_M");
            labelWolf_M->setText("current count of wolves: "+wolf_m);
            labelWolf_M->disable();

            std::string fence;
            fence = std::to_string(countOfFences());
            tgui::Label::Ptr labelFences = TGUI.get<tgui::Label>("labelFences");
            labelFences->setText("count of fences: "+fence);
            labelFences->disable();

            TGUI.draw(); // Draw all widgets
            window.display();
        }

    } else { // console mode
        nextStep();
    }
}

void Controller::initField(int nRabbits, int nWWolves, int nMWolves, int cOfFences)
{
    int index;
    bool animalAcquireHome = false;

    for (int i = 0; i < cOfFences; i++) {
        index = random_number(0, 399);
        field.getCells()->at(static_cast<unsigned long>(index)).setFence(true);
    }

    for (int i = 0; i < nRabbits; i++) {
        while (!animalAcquireHome) {
            index = random_number(0, 399);
            if (!field.getCells()->at(static_cast<unsigned long>(index)).isFence()) {
                field.getCells()->at(static_cast<unsigned long>(index)).getRabbits()->emplace_back(Rabbit());
                animalAcquireHome = true;
            }
        }
        animalAcquireHome = false;
    }
    for (int i = 0; i < nWWolves; i++) {
        while (!animalAcquireHome) {
            index = random_number(0, 399);
            if (!field.getCells()->at(static_cast<unsigned long>(index)).isFence()) {
                field.getCells()->at(static_cast<unsigned long>(index)).getWolf_W()->emplace_back(Wolf_W());
                animalAcquireHome = true;
            }
        }
        animalAcquireHome = false;
    }
    for (int i = 0; i<nMWolves; i++){
        while (!animalAcquireHome) {
            index = random_number(0, 399);
            if (!field.getCells()->at(static_cast<unsigned long>(index)).isFence()) {
                field.getCells()->at(static_cast<unsigned long>(index)).getWolf_M()->emplace_back(Wolf_M());
                animalAcquireHome = true;
            }
        }
        animalAcquireHome = false;
    }

    std::cout << "New field initialized." << std::endl;
    displayField();
}

int Controller::countOfRabbits(){
    int count=0;
    for(int index = 0; index < 400; index++) {
        count+=field.getCells()->at(static_cast<unsigned long>(index)).getRabbits()->size();
    }
    return count;
}

int Controller::countOfWolf_M(){
    int count=0;
    for(int index = 0; index < 400; index++) {
        count+=field.getCells()->at(static_cast<unsigned long>(index)).getWolf_M()->size();
    }
    return count;
}

int Controller::countOfWolf_W(){
    int count=0;
    for(int index = 0; index < 400; index++) {
        count+=field.getCells()->at(static_cast<unsigned long>(index)).getWolf_W()->size();
    }
    return count;
}
int Controller::countOfFences(){
    int count=0;
    for(int index = 0; index < 400; index++) {
        if(field.getCells()->at(static_cast<unsigned long>(index)).isFence()){
            count++;
        }
    }
    return count;
}


void Controller::restartField() {
    std::cout << "Restarting field ..." << std::endl;
    for(int index = 0; index < 400; index++) {
        field.getCells()->at(static_cast<unsigned long>(index)).getRabbits()->clear();
        field.getCells()->at(static_cast<unsigned long>(index)).getWolf_W()->clear();
        field.getCells()->at(static_cast<unsigned long>(index)).getWolf_M()->clear();
        if (field.getCells()->at(static_cast<unsigned long>(index)).isFence())
            field.getCells()->at(static_cast<unsigned long>(index)).setFence(false);
    }
    initSimulationParams();
    initField(nRabbits, nWWolves, nMWolves, cOfFences);
    tgui::Button::Ptr button_auto = TGUI.get<tgui::Button>("PlayAuto");
    button_auto->setText("Auto Play");

}

void Controller::displayField() {
    pView->displayField();
}

void Controller::nextStep() {
    // calculate decisions
    rabbitSpread();
    Wolf_MMakeOffspring();
    wolfTryToEatOrDie();
    calculateMoveDecisions(); // фаза прийняття рішень
    performMoves(); // фаза переходів
    currentStepNumber += 1;

    std::cout << "Step №" << currentStepNumber << std::endl;
    displayField();
}

std::vector<int> Controller::makeListOfAvailableStepsForWolf_W(int cellNumb) {
    auto neighbourCells = calculateNeighbourCellsWithoutFences(cellNumb); // (інти) номери доступних клітин з поточної
    std::vector<int> listOfAvailableStepsForWolf_W;
    bool rabbitExplored = false;
    for (auto& cllNmb: neighbourCells) {
        // якщо є хочаб один заєць на горизонті
        if (!field.getCells()->at(static_cast<unsigned long>(cllNmb)).getRabbits()->empty())
        {
            listOfAvailableStepsForWolf_W.emplace_back(cllNmb);
            rabbitExplored = true;
        }
    }
    if (rabbitExplored)
        return listOfAvailableStepsForWolf_W;
    else
        return neighbourCells;
}

std::vector<int> Controller::makeListOfAvailableStepsForRabbit(int cellNumb) {
    auto listOfAvailableStepsForRabbit = calculateNeighbourCellsWithoutFences(cellNumb);
    listOfAvailableStepsForRabbit.emplace_back(cellNumb);
    return listOfAvailableStepsForRabbit;
}

std::vector<int> Controller::calculateNeighbourCellsWithoutFences(int cellNumb) {
    std::vector<int> listOfNeighbours;
    // lambdas
    auto east = [](int numb) { return numb % 20 == 19 ? numb - 19 : numb + 1; };
    auto west = [](int numb) { return numb % 20 == 0 ? numb + 19 : numb - 1; };
    auto north = [](int numb) { return numb < 20 ? numb + 380 : numb - 20; };
    auto south = [](int numb) { return numb > 379 ? numb - 380 : numb + 20; };

    listOfNeighbours.emplace_back(east(cellNumb));
    listOfNeighbours.emplace_back(west(cellNumb));
    listOfNeighbours.emplace_back(north(cellNumb));
    listOfNeighbours.emplace_back(south(cellNumb));
    listOfNeighbours.emplace_back(east(south(cellNumb)));
    listOfNeighbours.emplace_back(west(south(cellNumb)));
    listOfNeighbours.emplace_back(east(north(cellNumb)));
    listOfNeighbours.emplace_back(west(north(cellNumb)));

//    std::cout << "LoN before: ";
//    for (auto& cllNmb: listOfNeighbours) {
//        std::cout << cllNmb << " ";
//    }
//    std::cout << std::endl;

    for (auto& cllNmb: listOfNeighbours) {
        if (field.getCells()->at(static_cast<unsigned long>(cllNmb)).isFence()) {
            // std::cout << "Fence at" << cllNmb << std::endl;
            listOfNeighbours.erase(std::remove(listOfNeighbours.begin(), listOfNeighbours.end(), cllNmb), listOfNeighbours.end());
        }
    }

//    std::cout << "LoN after: ";
//    for (auto& cllNmb: listOfNeighbours) {
//        std::cout << cllNmb << " ";
//    }
//    std::cout << std::endl;
    return listOfNeighbours;
}

void Controller::calculateMoveDecisions()
{
    std::cout << "Calc start" << std::endl;
    for(int cellNumb = 0; cellNumb < 400; cellNumb++)
    {
        // Rabbits
        auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits();
        if(!rabbitVec->empty())
        {
            for (auto& rabbit: *rabbitVec)
            {
                rabbit.chooseMoveDirection(makeListOfAvailableStepsForRabbit(cellNumb));
            }
        }

        //Wolf_W
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W();
        if(!Wolf_WVec->empty()){
            for(auto& wolf_w: *Wolf_WVec)
            {
                wolf_w.chooseMoveDirection(makeListOfAvailableStepsForWolf_W(cellNumb));
            }
        }

        //Wolf_M
        auto Wolf_MVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M();
        if(!Wolf_MVec->empty()){
            for(auto& wolf_m: *Wolf_MVec)
            {
                wolf_m.chooseMoveDirection(makeListOfAvailableStepsForWolf_M(cellNumb));
            }
        }
    }


    std::cout << "Calc end" << std::endl;
}

void Controller::performMoves()
{
    for(int cellNumb = 0; cellNumb < 400; cellNumb++)
    {
        // Rabbits
        auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits();
        if(!rabbitVec->empty())
        {
            for (auto& rabbit: *rabbitVec)
            {
                std::cout << "Curr cell: " << cellNumb << std::endl;
                std::cout << "Curr v size: " << rabbitVec->size() << std::endl;
                // якщо заєць вирішує лишитись тут же, то скіпнути виконання поточної ітерації щоб уникнути зайвих операцій
                int rabbitDecision = rabbit.getChosenMoveDirection();
                std::cout << "Rabbit decision is: " << rabbitDecision << std::endl;
                if(rabbitDecision == cellNumb or rabbitDecision < 0)
                    continue;
                else {
                    auto *destRabbitList = field.getCells()->at(static_cast<unsigned long>(rabbitDecision)).getRabbits();
                    std::cout << "Rabbit decision - go to: " << rabbitDecision << std::endl;
                    std::cout << "Dest v size: " << destRabbitList->size() << std::endl;
                    destRabbitList->insert(destRabbitList->end(), std::make_move_iterator(rabbitVec->begin()), std::make_move_iterator(rabbitVec->begin()+1));
                    std::cout << "Dest v size after insertion: " << destRabbitList->size() << std::endl;
                    rabbitVec->erase(rabbitVec->begin(), rabbitVec->begin()+1);
                    std::cout << "Curr v size after deletion: " << rabbitVec->size() << std::endl;
                    rabbit.setChosenMoveDirection(-2); // впевнитись, що цей кріль вже не буде задіяний в move на поточній ітерації.
                }
            }
        }

        // Wolf_W
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W();
        if(!Wolf_WVec->empty())
        {
            for (auto &wolf_w:*Wolf_WVec)
            {
                int wolf_w_decision = wolf_w.getChosenMoveDirection();
                if(wolf_w_decision == cellNumb or wolf_w_decision < 0)
                    continue;
                else{
                    field.getCells()->at(static_cast<unsigned long>(wolf_w_decision)).getWolf_W()->emplace_back(Wolf_W());//додаєм вовчицю в вектор вовчиць по вказаному номеру клітини
                    Wolf_WVec->pop_back();//видаляєм останній елемент з вектора
                    wolf_w.setChosenMoveDirection(-2);

                }

            }
        }

        //Wolf_M
        auto Wolf_MVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M();
        if(!Wolf_MVec->empty())
        {
            for (auto &wolf_m:*Wolf_MVec)
            {
                int wolf_m_decision = wolf_m.getChosenMoveDirection();
                if(wolf_m_decision == cellNumb or wolf_m_decision < 0)
                    continue;
                else{
                    field.getCells()->at(static_cast<unsigned long>(wolf_m_decision)).getWolf_M()->emplace_back(Wolf_M());//додаєм вовка в вектор вовків по вказаному номеру клітини
                    Wolf_MVec->pop_back();//видаляєм останній елемент з вектора
                    wolf_m.setChosenMoveDirection(-2);

                }

            }
        }
    }
}

void Controller::rabbitSpread() {
    for(int cellNumb = 0; cellNumb < 400; cellNumb++) {
        if(random_number(1, 5) == 1) {
            auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits();
            if(rabbitVec->size() == 1) {
                field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits()->emplace_back(Rabbit());
            }
            else {
                continue;
            }
        }
    }
}

void Controller::wolfTryToEatOrDie() {
    std::vector<Wolf_W>::iterator it;

    for (int cellNumber = 0; cellNumber < 400; cellNumber++){

        //Wolf_W
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getWolf_W();
        if (!Wolf_WVec->empty()) {
            for (auto& wolf_w: *Wolf_WVec) {
                auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getRabbits();
                if (!rabbitVec->empty()) {
                    wolf_w.setHealth(wolf_w.getHealth()+1) ;
                    rabbitVec->pop_back();
                }
                else {
                    wolf_w.setHealth(static_cast<float>(wolf_w.getHealth() - 0.1));
                }
            }

            for ( it = Wolf_WVec->begin(); it != Wolf_WVec->end(); ) {
                if ( (*it).getHealth() == 0.0f ) {
                    //delete * it;
                    it = Wolf_WVec->erase(it);
                }
                else {
                    ++it;
                }
            }

        }
        //Wolf_M

        std::vector<Wolf_M>::iterator iter;
        auto Wolf_MVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getWolf_M();
        if (!Wolf_MVec->empty()) {
            for (auto& wolf_m: *Wolf_MVec) {
                auto rabbitVec = field.getCells()->at(static_cast<unsigned long>(cellNumber)).getRabbits();
                if (!rabbitVec->empty()) {
                    wolf_m.setHealth(wolf_m.getHealth()+1) ;
                    rabbitVec->pop_back();
                }
                else {
                    wolf_m.setHealth(static_cast<float>(wolf_m.getHealth() - 0.1));
                }
            }

            for ( iter = Wolf_MVec->begin(); iter != Wolf_MVec->end(); ) {
                if ( (*iter).getHealth() == 0.0f ) {
                    //delete * iter;
                    iter = Wolf_MVec->erase(iter);
                }
                else {
                    ++iter;
                }
            }

        }

    }
}

std::vector<int> Controller::makeListOfAvailableStepsForWolf_M(int cellNumb) {
    auto neighbourCells = calculateNeighbourCellsWithoutFences(cellNumb);
    std::vector<int> listOfAvailableStepsForWolf_M;
    bool Wolf_WExplored = false;
    for (auto& cllNmb: neighbourCells){
        if (!field.getCells()->at(static_cast<unsigned long>(cllNmb)).getWolf_W()->empty()){
            listOfAvailableStepsForWolf_M.emplace_back(cllNmb);
            Wolf_WExplored = true;
        }
    }
    if(Wolf_WExplored){
        return listOfAvailableStepsForWolf_M;
    }
    //якщо не знайшли в одному із восьми квадратів вовчицю, то перевіряєм на наявність кролів, якщо і кролів немає - то повертаєм просто список клітин куди можна піти
    else{
        bool rabbitExplored = false;
            for (auto& cllNmb: neighbourCells) {
                if (!field.getCells()->at(static_cast<unsigned long>(cllNmb)).getRabbits()->empty())
                {
                    listOfAvailableStepsForWolf_M.emplace_back(cllNmb);
                    rabbitExplored = true;
                }
            }
        if(rabbitExplored){
            return listOfAvailableStepsForWolf_M;
            }
        else{
            return neighbourCells;
            }

    }
}

void Controller::Wolf_MMakeOffspring(){
    for (int cellNumb = 0; cellNumb < 399;cellNumb++){
        auto Wolf_WVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W();
        auto Wolf_MVec = field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M();
        int Wolf_WSize = static_cast<int>(Wolf_WVec->size());
        int Wolf_MSize = static_cast<int>(Wolf_MVec->size());
        bool wolf_wFound = false;
        if(!field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W()->empty()){
            wolf_wFound = true;
        }
        bool wolf_mFound = false;
        if(!field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M()->empty()){
            wolf_mFound = true;
        }
        bool rabbitFound = false;
        if(!field.getCells()->at(static_cast<unsigned long>(cellNumb)).getRabbits()->empty()){
            rabbitFound = true;
        }
        int BabyCount = 0;
        if(wolf_wFound && wolf_mFound && !rabbitFound){
            if(Wolf_MSize == Wolf_WSize){
                BabyCount = Wolf_MSize;
            }
            if(Wolf_MSize > Wolf_WSize){
                BabyCount = Wolf_WSize;
            }
            if(Wolf_MSize < Wolf_WSize){
                BabyCount = Wolf_MSize;
            }
            for(int baby = 0; baby < BabyCount; baby++){
                int gender = random_number(0,1);
                if(gender == 0){
                    field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_W()->emplace_back(Wolf_W());
                }
                else{
                    field.getCells()->at(static_cast<unsigned long>(cellNumb)).getWolf_M()->emplace_back(Wolf_M());
                }
            }
        }

    }
}

GUIView *Controller::getPGUIView() {
    return dynamic_cast<GUIView *>(pView);
}

void Controller::initSimulationParams() {
    // later this data should be loaded from XML/JSON/FILE.
    windowTitle = "Wolf Island simulation";
    nRabbits = 12;
    nMWolves = 4;
    nWWolves = 3;
    cOfFences = 5;
    currentStepNumber = 0;
    useGUI = true;
    FPS = 60; // оптимально, щоб комп був в нормі. З дефолтним значенням проц взлітає.
    delayTimeInSeconds = seconds(1);
}

void Controller::initWindow() {
    window.create(VideoMode(896, 640), windowTitle);
    window.setFramerateLimit(FPS);
    TGUI.setWindow(window); // Create the gui and attach it to the window
}

void Controller::initView() {
    if(useGUI) {
        initWindow();
        pView = new GUIView(&field, &window, &TGUI);
    } else {
        pView = new ConsoleView(&field);
    }
}
