#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "Card.h"
#include <time.h>

using std::vector;
const int deck_size = 50;

#pragma once
class Player
{
	private:
		int actual;
		void shuffle();

	public:
		Player();
		vector<Card*> deck;
		int add_card_deck(int id);
		void show_deck();
		void create_deck();
		void draw_card(int n);

};

