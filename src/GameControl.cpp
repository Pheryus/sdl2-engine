#include "GameControl.h"
#include "TextureBank.h"
#include "System.h"

GameControl::GameControl(){
    Running = true;
    event = Event::GetInstance();
    this->system = System::GetInstance();

    System* system = (System*)this->system;
    system->ResizeWindow(1366,768);
    TextureBank::LoadFolder("Textures/Cards_bd"); //Heavy load Stage
}

bool GameControl::IsRunning(){
    return Running;
}

int GameControl::GetState(){
    return state;
}

void GameControl::SetState(int state){
    this->state = state;
}

void GameControl::Update(){
    manageEvents();
    manageCollisions();
    ManageInteractions();
}

void GameControl::ManageEvents() {
    if (event->QuitRequest())
        Running = false;
}

void GameControl::ManageCollisions(){}

void GameControl::ManageInteractions(){
  GameObject* host, interested;
  while(!InteractFrom.empty() && !InteractTo.empty()){
    host = InteractFrom.top();
    interested = InteractTo.top();
    InteractFrom.pop();
    InteractTo.pop();
    host->Interact(interested);
  }
  if (InteractFrom.empty())
    InteractTo.clear();
}

void GameControl::RequestInteraction(GameObject* go){
  InteractFrom.push(go);
}

void GameControl::ReceiveToInteraction(GameObject* go){
  InteractTo.push(go);
}

void GameControl::Run(){
    System* system = (System*)this->system;
    system->SetGameControl(this);
    /*srand(time(NULL));
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
