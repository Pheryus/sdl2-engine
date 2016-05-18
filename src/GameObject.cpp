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
	alive = true;
	active = true;
}

void GameObject::SetPos(int x, int y){
	dest.x = x;
	dest.y = y;
}

void GameObject::Update(){}

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

Mask* GameObject::GetCurrentMask(){
	return TextureBank::GetMasks(ID)->at(Current);
}

SDL_Point GameObject::GetPos(){
	SDL_Point p = {dest.x, dest.y};
	return p;
}

void GameObject::SetCurrentSprite(int index){
	Current = index;
	src = TextureBank::GetRects(ID)->at(Current);
}

bool GameObject::IsAlive(){
	return alive;
}

void GameObject::SetAlive(bool alive){
	this->alive = alive;
}

bool GameObject::IsActive(){
	return active;
}

void GameObject::SetActive(bool active){
	this->active = active;
}

void GameObject::Resize(float prop){
	dest.w *= prop;
	dest.h *= prop;
}

void GameObject::RequestInteraction(){
	GameControl* gc = System::GetInstance()->GetGameControl();
	gc->RequestInteraction(this);
}

void GameObject::SendToInteraction(){
	GameControl* gc = System::GetInstance()->GetGameControl();
	gc->ReceiveToInteraction(this);
}

void GameObject::Interact(GameObject* other){}
