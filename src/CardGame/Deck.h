#ifndef __STACK_H__
	#define __STACK_H__
#include "../GameObject.h"
#include "Card.h"
#include <stack>
#include <string>

class Stack : protected GameObject{
	public:
		Stack(std::string);
		void Update();
		void AddCard(Card*);
		Card* DrawCard();
		void 
	private:
		std:stack<Card*> deck;

};

#endif
