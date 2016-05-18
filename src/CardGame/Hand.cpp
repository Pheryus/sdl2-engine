#include "Hand.h"
#include "../System.h"


Hand::Hand (bool player){
	mainPlayer = player;
}

void Hand::AddCard(Card* card){
	hand.push_back(card);
	playable.push_back(false);
}

Card* Hand::DropCard(int i){
	Card* temp = (Card*) (hand.begin() + i);
	hand.erase(hand.begin()+i);
	playable.erase(playable.begin()+i);
	return temp;
}