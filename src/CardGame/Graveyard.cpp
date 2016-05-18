#include "Graveyard.h"
#include "../System.h"
#include <climits>

Graveyard::Graveyard() : Deck(){
    max_cards = INT_MAX;
}

Graveyard::~Graveyard(){
    Card* c;
    while(!deck.empty()){
        c = deck.top();
        deck.pop();
        delete c;
    }
}

void Graveyard::AddCard(Card* c){
    if (!deck.empty())
        System::GetInstance()->RemGameObject(deck.top()); // Remove carta de cima anterior das listas de update e render
    deck.push(c);
    c->SetPos(0,0); //TODO
}

Card* Graveyard::DrawCard(){
    Card* c = deck.top();
    deck.pop();
    if (!deck.empty())
        System::GetInstance()->AddGameObject(deck.top()); // Add carta de cima nova nas listas de update e render
    return c;
}

void Graveyard::Update(){

}
