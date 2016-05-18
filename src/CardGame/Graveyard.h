#ifndef __GRAVEYARD_H__
    #define __GRAVEYARD_H__

#include "Deck.h"

class Graveyard : public Deck {
public:
    Graveyard();
    ~Graveyard();
    void AddCard(Card*);
    void Update();
}

#endif
