#include "Line.h"

Line::Line(bool isFront) : isFront(isFront){
    cards.fill(NULL);
    x = y = 0;
}

void Line::AddCard(Card* c, int pos){
    cards[pos] = c;
    c->SetPos(x,y); //TODO arrumar pos
}

Card* Line::DropCard(int pos){
    Card* c = cards[pos];
    cards[pos] = NULL;
    return c;
}

Card* Line::DropCard(std::string ID){
    Card* c = NULL;
    for(int i=0; i<cards.size(); i++)
        if (cards[i] != NULL)
            if (cards[i]->GetID() == ID){
                c = cards[i];
                cards[i] = NULL;
            }
    return c;
}

void Line::SetPos(int x, int y){
    this->x = x;
    this->y = y;
    for(int i=0; i<cards.size(); i++)
        if (cards[i] != NULL)
            cards[i]->SetPos(x,y); //TODO Calcular novas posições
}
