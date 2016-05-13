#include "PlayGame.h"


PlayGame::PlayGame(int id_deck) : GameControl() {

	vector<Card*> deck_cards = DataBase::Init("0");
	TextureBank::LoadFolder("Textures/Cards_bd");
	System* sys = (System*) system;
	
	for (int i=0; i < DECKSIZE; i++){
		GameObject* card = new GameObject(to_string(decK_cards[0]->getID());
		sys->AddGameObject(card);
	}

}

PlayGame::update(){
	
}

PlayGame::manageEvents(){
	
}

PlayGame::manageCollisions(){

}
