#include <stdlib.h>
#include <vector>
#include "Card.h"

const int deck_size = 50;
#pragma once
class In_Play
{
	static vector <Card*> mao;
	static vector <Card*> front_line, back_line, permanents;
	static vector <Card*> deck;

public:
	int* hand;

};

