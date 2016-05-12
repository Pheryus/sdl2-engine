#ifndef __GAMEOBJECT_H__
	#define __GAMEOBJECT_H__

#include <string>
#include <SDL2/SDL.h>
#include "Mask.h"

class GameObject{
	protected:
		int 	 	Current;
		void 	 	SetCurrentSprite(int);
		SDL_Rect	src, dest;
		bool		alive;
		bool		active;
		std::string ID;

	public:
		GameObject(std::string);
		virtual void Update();
		virtual void Render();
		bool Collide(GameObject*);
		bool CollidePoint(int, int);
		Mask* 	    GetCurrentMask();
		SDL_Point   GetPos();
		void 		SetPos(int, int);
		std::string GetID();
		bool		isAlive();
		void 		setAlive(bool);
		bool		isActive();
		void 		setActive(bool);
		void 		resize(float);
};
#endif
