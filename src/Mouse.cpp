/*
 * File:   Mouse.cpp
 * Author: vinicius
 *
 * Created on 18 de Abril de 2016, 22:16
 */

#include "Mouse.h"

Mouse::Mouse(std::string ID) : GameObject(ID){
    mouse_rect = {200,200,50,50};
}

void Mouse::setPosition(){
    dest.x = mouse_position.x;
    dest.y = mouse_position.y;
    Log("%d %d\n", dest.x,dest.y);
    //mouse_rect.x = mouse_position.x;
    //mouse_rect.y = mouse_position.y;
}

void Mouse::getPosition(){
    SDL_GetMouseState(&mouse_position.x, &mouse_position.y);
}

void Mouse::Update(SDL_Event* e){
    if (e->type == SDL_MOUSEMOTION)
    	Moviment(e);
    if (e->type == SDL_MOUSEBUTTONDOWN)
    	MouseLeftClick(e);
    if (e->type == SDL_MOUSEBUTTONUP){
    	left_hold = 0;
    	//std::cout << left_hold << std::endl;
    }
}

void Mouse::Moviment(SDL_Event*){
	SDL_GetMouseState( &mouse_position.x, &mouse_position.y );
    setPosition();
    //std::cout << mouse_position.x << " " << mouse_position.y << std::endl;
}

void Mouse::MouseLeftClick(SDL_Event* e){
    if (e->button.button == SDL_BUTTON_LEFT){
      left_hold = 1;
      Log("Left click !");
      std::cout << mouse_rect.x << " " << mouse_rect.y << std::endl;
      //std::cout << left_hold << std::endl;
    }
}

void Mouse::IntersecRect(SDL_Rect* r){
	//for(int i=0;i<2;i++){
		/*if (SDL_HasIntersection(mouse_rect,r)){
			if(left_hold == 1)
				CardMove(r);/*
		}
	//}*/
}

void Mouse::CardMove(SDL_Rect r){
	r = {mouse_position.x,mouse_position.y};
}

//void Mouse::ImgFollow(){

//}


Mouse::~Mouse() {
}
