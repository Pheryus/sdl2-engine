#include <sqlite3.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "../CardGame/Player.h"

class DataBase{
	public:
		static std::vector<Card*> Init(std::string address);
	private:
		static std::vector<Card*> db_cards;
		static int callback(void *NotUsed, int argc, char **argv, char **azColName);
};


