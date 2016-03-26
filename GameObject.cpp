#include "GameObject.h"
#include "FileManager.h"
#include "Stringify.h"

GameObject::GameObject(string ID) : ID(ID){
	// Redefine later
	dest.x = 0;
	dest.y = 0;
	dest.w = TextureBank::Get(ID)->GetWidth();
	dest.h = TextureBank::Get(ID)->GetHeight();
	src.x = dest.x;
	src.y = dest.y;
	src.w = dest.w;
	src.h = dest.h;
	LoadMasks();
}

GameObject::~GameObject(){
	for (Mask* m : masks)
		delete m;
	Log("[ OK ] %s cleaned",ID.data());
}

void GameObject::Update(){}

void GameObject::Render(){
	TextureBank::Get(ID)->Render(
		dest.x, dest.y, dest.w, dest.h,
		src.x, src.y, src.w, src.h);
}

bool GameObject::Collide(GameObject* g){
	return masks[CurrentMask]->Overlap(
		g->GetCurrentMask(),
		g->GetPos().x - dest.x,
		g->GetPos().y - dest.y
	);
}

string GameObject::GetID(){
	return ID;
}

Mask* GameObject::GetCurrentMask(){
	return masks[CurrentMask];
}

SDL_Point GameObject::GetPos(){
	SDL_Point p = {dest.x, dest.y};
	return p;
}

void GameObject::LoadMasks(){
	Log("[ .. ] Loading masks from %s...",ID.data());
	SDL_Rect r;
	string raw = FileManager::GetContents("Masks/"+ID);
	vector<string> rects = Stringify::Explode(raw, "\n");
	SDL_Texture* t = TextureBank::Get(ID)->GetMaskTexture();
	for (string rect : rects){
		if (rect == "") continue;
		vector<string> values = Stringify::Explode(rect, " ");
		r.x = Stringify::ToInt(values[0]);
		r.y = Stringify::ToInt(values[1]);
		r.w = Stringify::ToInt(values[2]);
		r.h = Stringify::ToInt(values[3]);
		masks.push_back(new Mask(t, r, TextureBank::Get(ID)->GetPitch()));
	}
	TextureBank::Get(ID)->DestroyMaskTexture();
	Log("[ OK ] Masks from %s loaded.",ID.data());
}
