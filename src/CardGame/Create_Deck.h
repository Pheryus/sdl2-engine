#ifndef __CREATE_DECK_H__
	#define __CREATE_DECK_H__

#include <vector>
#include <stdio.h>

const int SIZE_DECK = 40;
const int INI_CARDS = 40;

class Create_Deck{

	static std::vector <int> id_cards;

	public:
		static int Init();
		static void save_deck();
};

#endif