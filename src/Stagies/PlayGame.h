#ifndef __PLAYGAME_H__
	#define __PLAYGAME_H__

#include "../GameControl.h"
#include "../DataBase/Database.h"
#include "../CardGame/Card.h"
#include <vector>
#include <sqlite3.h>

using namespace std;

#define DECKSIZE 40;
#define PI 3.1415926535897932384626433832795028841

class PlayGame : protected GameControl {

	PlayGame(int id_deck);

	void update();

	void manageEvents();

	void manageCollisions();


};


#endif