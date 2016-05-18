#ifndef __GAMEOBJECT_H__
	#define __GAMEOBJECT_H__

#include <string>
#include <SDL2/SDL.h>
#include "Mask.h"
#include <iostream>


class GameObject{
	protected:
		int 	 	Current;
		void 	 	SetCurrentSprite(int);
		void 		RequestInteraction();
		void 		SendToInteraction();
		bool		alive;
		bool		active;
		SDL_Rect		src, dest;
		std::string ID;

	public:
		SDL_Rect	src, dest;
		GameObject(std::string);
		virtual void Update();
		virtual void Update(SDL_Event*);
		virtual void Render();
		virtual void Interact(GameObject*);
		bool Collide(GameObject*);
		bool CollidePoint(int, int);
		Mask* GetCurrentMask();
		SDL_Point GetPos();
		void SetPos(int, int);
		std::string GetID();
		bool		IsAlive();
		void 		SetAlive(bool);
		bool		IsActive();
		void 		SetActive(bool);
		void 		Resize(float);
};
#endif
