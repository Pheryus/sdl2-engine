//==============================================================================
/*
	Run the System from here!
*/
//==============================================================================
#include "System.h"
#include <vector>
#include "GameObject.h"
int main(int argc, char* argv[]) {
	// if system succesfull starts
	if (System::GetInstance()->Init()){
		GameObject* Mario = new GameObject("Test");
		// add game object to render and update routines
		System::GetInstance()->AddGameObject(Mario);
		// do the system execute the game
		System::GetInstance()->Execute();
		// Cleanup System
		System::GetInstance()->Quit();
		// Free up your resources!
		delete Mario;
	}
}
