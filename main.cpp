
#undef main
#include "App.h"
#include <sqlite3.h>
#include <vector>
#include "GameObject.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "CardGame/Card.h"
#include "CardGame/Player.h"
#include "CardGame/Create_Deck.h"
#include "DataBase/DataBase.h"

using namespace std;
//Screen dimension constant
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* argv[])
{
   std::vector<Card*> aux = DataBase::Init("cartas.db");
   if (App::GetInstance()->Init()){
		GameObject* vinnie = new GameObject("Test");
		std::vector<GameObject*> gebinha;
		gebinha.push_back(new GameObject("Test"));
		delete gebinha[0];
		gebinha.clear();
		return App::GetInstance()->Execute(argc, argv);
	}
}
