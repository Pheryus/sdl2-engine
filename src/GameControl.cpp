#include "GameControl.h"
#include "TextureBank.h"
#include "System.h"

GameControl::GameControl(){
    Running = true;
    event = Event::GetInstance();
    this->system = System::GetInstance();

    System* system = (System*)this->system;
    system->SetGameControl(this);
    TextureBank::LoadFolder("Textures/Cards_bd");
    system->Resize(1366,768);
}

bool GameControl::isRunning(){
    return Running;
}

void GameControl::update(){
    manageEvents();
    manageCollisions();
}

void GameControl::manageEvents() {
    if (event->QuitRequest())
        Running = false;
}

void GameControl::manageCollisions(){}

void GameControl::Run(){
    System* system = (System*)this->system;
    srand(time(NULL));
    char num[4];
    sprintf(num,"%d",(rand()%153)+1);
    GameObject* Mario = new GameObject("Test");
    GameObject* Card = new GameObject(num);
    system->AddGameObject(Mario);
    system->AddGameObject(Card);
    Card->SetPos(600,100);
    Card->Resize(0.5);
    system->Execute();
    delete Mario;
    delete Card;
}
