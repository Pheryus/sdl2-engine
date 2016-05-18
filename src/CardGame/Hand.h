#ifndef __HAND_H__
	#define __HAND_H__

#include <list>
#include "Card.h"
#include <string>
#include <vector>

class Hand {
	private:
		std::list<Card*> hand;
		bool mainPlayer;
		std::vector<bool> playable;

	public:
		void AddCard(Card* card);
		Card* DropCard(int);
		Card* DropCard(std::string);
		Hand(bool); //definir se a mao eh do jogador principal
		void Update();
		void Render();

};

#endif