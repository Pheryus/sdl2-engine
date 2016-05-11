#undef main
#include "System.h"
#include <sqlite3.h>
#include <vector>
#include <iostream>
#include <string.h>
#include "GameObject.h"
#include "CardGame/Card.h"
#include "CardGame/Player.h"
#include "CardGame/In_Play.h"
#include "DataBase/DataBase.h"

using namespace std;
//Screen dimension constant
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
	
	vector<Card*> deck_cards = DataBase::Init("0");

	if (System::GetInstance()->Init()){
		TextureBank::LoadFolder("Textures/Cards_bd");
		for (int i=0; i < 6; i++){
				GameObject* test = new GameObject(to_string(deck_cards[2*i]->GetID()));	
				test->SetPos(149*i,300);
				test->Rediment(0.5);
				System::GetInstance()->AddGameObject(test);
			}
		System::GetInstance()->Execute();
	}
}
