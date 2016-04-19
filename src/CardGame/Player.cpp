#include "Player.h"


Player::Player(){
	actual = deck_size;
}
	
void Player::show_deck(){
	for (int i = 0; i < actual; i++)
		printf("card %d in deck\n", deck[i]);
}

/*
void Player::shuffle(){
	int x;
	int i;
	int aux;
	srand(time(NULL));
	for (i = 0; i< deck_size; i++){
		x = rand() % deck_size;
		aux = deck[actual][i];
		deck[actual][i] = deck[actual][x];
		deck[actual][x] = aux;
	}

}


void Player::draw_card(int n){
	
	if (!deck[actual].size()){
		if (n > 0){
			deck[actual].pop_back();
			Player::draw_card(n - 1);
			//function that add a card to hand
		}
	}
	else{
		//lose the game
		printf("You lose the game yeahhhh!\n");
		return;
	}

}
*/
