#ifndef __GAMEOBJECT_H__
	#define __GAMEOBJECT_H__

#include <string>
#include <SDL2/SDL.h>
#include "Mask.h"
#include <iostream>
class GameObject{
	private:
		int 	 	Current;
		void 	 	SetCurrentSprite(int);
		SDL_Rect	src, dest;
		bool		alive;
		std::string ID;

	public:
		GameObject(std::string);
		virtual void Update();
		virtual void Render();
		bool Collide(GameObject*);
		Mask* 	    GetCurrentMask();
		SDL_Point   GetPos();
		void 		SetPos(int, int);
		std::string GetID();
		bool		isAlive();
};
#endif
