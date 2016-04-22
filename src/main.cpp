//==============================================================================
/*
	Run the app!

	3/11/2014
    SDLTutorials.com
    Tim Jones
*/
//==============================================================================
#include "System.h"
#include <vector>
#include "GameObject.h"
int main(int argc, char* argv[]) {
	if (System::GetInstance()->Init()){
		GameObject* vinnie = new GameObject("Test");
		System::GetInstance()->AddGameObject(vinnie);
		System::GetInstance()->Execute();
		delete vinnie;
	}
}
