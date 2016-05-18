#ifndef __LINE_H__
    #define __LINE_H__

#include <array>
#include "Card.h"
#include <string>

class Line{
public:
    Line(bool);
    void AddCard(Card*, int);
    Card* DropCard(int);
    Card* DropCard(std::string);
    void SetPos(int, int);
private:
    bool isFront;
    std::array<Card*,4> cards;
    int x, y;
};

#endif
