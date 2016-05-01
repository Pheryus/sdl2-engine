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
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]) {
	//In_Play::SetDeckPlayer1("0");	
	if (System::GetInstance()->Init()){
		//TextureBank::LoadFolder("Textures/Cards_bd");
		GameObject* test = new GameObject("2");
		System::GetInstance()->AddGameObject(test);
		System::GetInstance()->Execute();
	}
}
