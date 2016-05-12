#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "../GameObject.h"

using namespace std;
#pragma once 


class Card : protected GameObject
{
private:
	int power, lt, res;
	int id_card;
	int pri_cost, sec_cost;
	string name, type, color, desc;

public:
	Card(char** values);
	int is_equal(char* ct, char* type);
	void print();
	int GetID();
};
