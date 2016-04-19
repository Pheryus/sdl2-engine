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
	if (App::GetInstance()->Init()){
		GameObject* vinnie = new GameObject("Test");
		std::vector<GameObject*> gebinha;
		gebinha.push_back(new GameObject("Test"));
		delete gebinha[0];
		gebinha.clear();
		return App::GetInstance()->Execute();
	}
}
