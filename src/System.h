//==============================================================================
/*
	Primary Systemlication class

	3/11/2014
	SDLTutorials.com
	Tim Jones
*/
//==============================================================================
#ifndef __SYSTEM_H__
	#define __SYSTEM_H__

#include <SDL2/SDL.h>
#include <vector>

#include "TextureBank.h"
#include "GameObject.h"
#include "GameControl.h"

class System {
	private:
		static System Instance;
		int WindowWidth;
		int WindowHeight;

		SDL_Window* Window = NULL;
		SDL_Renderer* Renderer = NULL;
		SDL_Surface* PrimarySurface = NULL;

		// GameObjects e GameControl
		std::vector<std::vector<GameObject*>> gameObjects;
		GameControl* gameControl;

	protected:
		System();
		void SeekEvents();	// Capture SDL Events
		void Loop();		// Logic loop
		void Render();		// Render loop (draw)

	public:
		static System* GetInstance();	// Get a instance of this class
		bool Init();					// Initialize our SDL game / System
		void Quit();
		void SetFullScreen();
		void ResizeWindow(int,int);
		int Execute();
		int Execute(bool*);

	public:
		SDL_Renderer* GetRenderer();
		void AddGameObject(void*);
		void AddGameObject(void*, int);
		void RemGameObject(void*);
		int GetWindowWidth();
		int GetWindowHeight();
		void SetGameControl(GameControl*);
		GameControl* GetGameControl();
};

#endif
