#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "Card.h"
#include <time.h>


class Player
{
	private:
		int actual;
		void shuffle();

	public:
		Player();
		int add_card_deck(int id);
		void show_deck();
		void create_deck();
		void draw_card(int n);

};

