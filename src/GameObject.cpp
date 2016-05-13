#include "GameObject.h"
#include "FileManager.h"
#include "Stringify.h"
#include "TextureBank.h"
#include "System.h"

GameObject::GameObject(std::string ID) : ID(ID){
	SetCurrentSprite(0);
	dest.x = 0;
	dest.y = 0;
	dest.w = src.w;
	dest.h = src.h;
	window = System::GetInstance()->GetMonitor();
	ResizeImage(window);
	alive = true;
	active = true;
}

void GameObject::SetPos(int x, int y){
	dest.x = x;
	dest.y = y;
	ResizeCoor();
}

void GameObject::Update(){}

void GameObject::Update(SDL_Event* Event){}

void GameObject::Render(){
	if (active)
		TextureBank::Get(ID)->Render(
			dest.x, dest.y, dest.w, dest.h,
			src.x, src.y, src.w, src.h);
}

bool GameObject::Collide(GameObject* g){
	return GetCurrentMask()->Overlap(
		g->GetCurrentMask(),
		g->GetPos().x - dest.x,
		g->GetPos().y - dest.y
	);
}

bool GameObject::CollidePoint(int x, int y){
	return GetCurrentMask()->CollidePoint(x-dest.x, y-dest.y);
}

std::string GameObject::GetID(){
	return ID;
}

void GameObject::SetID(std::string id){
	ID = id;
}

Mask* GameObject::GetCurrentMask(){
	return TextureBank::GetMasks(ID)->at(Current);
}

SDL_Point GameObject::GetPos(){
	SDL_Point p = {dest.x, dest.y};
	return p;
}

void GameObject::ResizeCoor(float v){
		dest.x *= window;
		dest.y *= window;
}

void GameObject::ResizeImage(float v){
	dest.w *= v;
	dest.h *= v; 
}

void GameObject::SetCurrentSprite(int index){
	Current = index;
	src = TextureBank::GetRects(ID)->at(Current);
}

bool GameObject::isAlive(){
	return alive;
}

void GameObject::setAlive(bool alive){
	this->alive = alive;
}

bool GameObject::isActive(){
	return active;
}

void GameObject::setActive(bool active){
	this->active = active;
}


