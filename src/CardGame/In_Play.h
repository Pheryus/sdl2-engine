#include <stdlib.h>
#include <vector>
#include "Card.h"
#include "../DataBase/DataBase.h"

class In_Play
{
	/*
	static vector <Card*> mao1, mao2;
	static vector <Card*> front_line, front_line2, back_line, back_line2, permanents, permanents2;
	static vector <Card*> deck, deck2;
	*/

public:
	static int* hand;
	static void SetDeckPlayer1(int);
	static int GetCardPlayer1(int i);
};

