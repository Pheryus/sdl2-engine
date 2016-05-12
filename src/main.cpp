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

int main(int argc, char* argv[]) {
	
	
	
	if (System::GetInstance()->Init()){
		TextureBank::LoadFolder("Textures/Cards_bd");
		Mouse* mouse = new Mouse("leticia_cursor");
		//GameObject* mouse_texture = new GameObject("Test");
				//mouse_texture->SetPos(400,100);
				//mouse->Rediment(0.5);
				System::GetInstance()->AddGameObject((GameObject*)mouse);
		for (int i=0; i < 6; i++){
				GameObject* test = new GameObject(to_string(deck_cards[2*i]->GetID()));	
				test->SetPos(149*i,300);
				System::GetInstance()->AddGameObject(test,1);
			}
	}
		System::GetInstance()->Execute();
}
