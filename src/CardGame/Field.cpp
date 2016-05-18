#include "Field.h"
#include "../System.h"

Field::Field(bool mainPlayer) : GameObject("field"){
    front = new Line(true);
    back  = new Line(false);
    this->mainPlayer = mainPlayer;
    System* sys = System::GetInstance();
    int w = sys->GetWindowWidth(), h = sys->GetWindowHeight();
    //TODO: setar posições dos componentes
    if (mainPlayer){
        SetPos(w,h);
        front->SetPos(w,h);
        back->SetPos(w,h);
    }
    else{
        SetPos(w,h);
        front->SetPos(w,h);
        back->SetPos(w,h);
    }
}

Field::~Field(){
    delete front;
    delete back;
}

void Field::AddCard(Card* card, bool frontLine, int pos){
    if (frontLine)
        front->AddCard(card, pos);
    else
        back->AddCard(card, pos);
}

Card* Field::DropCard(bool frontLine, int pos){
    if (frontLine)
        return front->DropCard(pos);
    else
        return back->DropCard(pos);
}

Card* Field::DropCard(bool frontLine, std::string ID){
    if (frontLine)
        return front->DropCard(ID);
    else
        return back->DropCard(ID);
}

void Field::Update(){

}
