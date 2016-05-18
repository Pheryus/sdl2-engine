#include "Deck.h"
#include <vector>       // vector
#include <random>       // default_random_engine
#include <chrono>       // chrono::system_clock
#include <algorithm>    // shuffle
using namespace std;

Deck::Deck() : GameObject("pilha"){
}

void Deck::AddCard(Card* c){
    if (deck.size() < max_cards)
        deck.push(c);
}

Card* Deck::DrawCard(){
    if (deck.empty())
        return NULL;
    Card* c = deck.top();
    deck.pop();
    return c;
}

void Deck::Shuffle(){
    vector<Card*> temp;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    while(!deck.empty()){
        temp.push_back(deck.top());
        deck.pop();
    }
    shuffle(temp.begin(), temp.end(), default_random_engine(seed));
    for (Card* c : temp)
        deck.push(c);
    temp.clear();
}

void Deck::Update(){
}
