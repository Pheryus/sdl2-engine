#ifndef __DECK_H__
	#define __DECK_H__
#include "../GameObject.h"
#include "Card.h"
#include <stack>
#include <string>

class Deck : protected GameObject{
	public:
		Deck();
		void Update();
		void AddCard(Card*);
		Card* DrawCard();
		void Shuffle(); //Embaralha

	protected:
		std::stack<Card*> deck;
		int max_cards;
};

#endif
