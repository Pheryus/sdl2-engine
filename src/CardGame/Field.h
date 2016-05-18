#ifndef __FIELD_H__
    #define __FIELD_H__

#include "Card.h"
#include "Line.h"
#include <string>

class Field : public GameObject{
public:
    Field(bool);
    ~Field();
    void AddCard(Card*, bool, int);
    Card* DropCard(bool, int);
    Card* DropCard(bool, std::string);
    void Update();

private:
    Line *front, *back;
    bool mainPlayer;
};

#endif
