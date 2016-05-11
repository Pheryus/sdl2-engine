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
#include <string>
#include <stdio.h>
#include "TextureBank.h"
#include "GameObject.h"

class System {
	private:
		static System Instance;

		bool Running = true;

		SDL_Window* Window = NULL;
		SDL_Renderer* Renderer = NULL;
		SDL_Surface* PrimarySurface = NULL;

		static const int WindowWidth = 1024;
		static const int WindowHeight = 600;
		// GameObjects
		std::vector<std::vector<GameObject*>> gameObjects;
		GameObject* mouse;
		int actual;

	private:
		System();

		// Capture SDL Events
		void OnEvent(SDL_Event* Event);

		// Logic loop
		void Loop();

		// Render loop (draw)
		void Render();

		// Free up resources
		void Cleanup();

	public:
		int Execute();
		int Execute(bool*);

	public:
		// Initialize our SDL game / System
		bool Init();
		SDL_Renderer* GetRenderer();
		void AddGameObject(GameObject*);
		void AddGameObject(GameObject*, int);
		void RemGameObject(GameObject*);

	public:
		static System* GetInstance();

		static int GetWindowWidth();
		static int GetWindowHeight();
};

#endif
