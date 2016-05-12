#include "In_Play.h"

std::vector <Card*> In_Play::deck;

void In_Play::SetDeckPlayer1(std::string db){
	deck = DataBase::Init(db);
}

int In_Play::GetCardPlayer1(int i){
	return deck[i]->GetID();
}
