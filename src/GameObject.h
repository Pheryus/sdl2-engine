#ifndef __GAMEOBJECT_H__
	#define __GAMEOBJECT_H__

#include <string>
#include <SDL2/SDL.h>
#include "Mask.h"
#include <iostream>


class GameObject{
		private:
		int 	 	Current;
		float window;
		void 	 	SetCurrentSprite(int);
		
		bool		alive;
		std::string ID;

	public:
		SDL_Rect	src, dest;
		GameObject(std::string) ;
		virtual void Update();
		virtual void Update(SDL_Event*);
		virtual void Render();
		bool Collide(GameObject*);
		Mask* 	    GetCurrentMask();
		SDL_Point   GetPos();
		void 		SetPos(int, int);
		std::string GetID();
		bool		isAlive();
		void ResizeImage();
		void ResizeCoor();
		void SetID(std::string id);

};
#endif
