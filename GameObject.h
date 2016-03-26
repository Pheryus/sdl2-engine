#ifndef __GAMEOBJECT_H__
	#define __GAMEOBJECT_H__

#include <string>
#include <vector>
#include "Mask.h"
#include "TextureBank.h"
#include <SDL2/SDL.h>
using namespace std;

class GameObject{
	private:
		string ID;
		SDL_Rect src, dest;
		vector<Mask*> masks;
		int CurrentMask = 0;
		void LoadMasks();

	public:
		GameObject(string);
		~GameObject();
		void Update();
		void Render();
		bool Collide(GameObject*);
		string GetID();
		Mask* GetCurrentMask();
		SDL_Point GetPos();
};
#endif
