/*
 * File:   Mouse.h
 * Author: vinicius
 *
 * Created on 18 de Abril de 2016, 22:16
 */

#ifndef MOUSE_H
#define	MOUSE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_mouse.h>
#include <stdio.h>
#include <iostream>
#include "Log.h"
#include <vector>
#include "GameObject.h"
#include <string>

class Mouse: public GameObject {
public:
    SDL_Point mouse_position;
    SDL_Rect mouse_rect;
    int left_hold = 0;
    Mouse(std::string);
    virtual ~Mouse();
    void setPosition();
    void getPosition();
    void Update(SDL_Event* e);
    void Moviment(SDL_Event* e);
    void MouseLeftClick(SDL_Event* e);
    void IntersecRect(SDL_Rect* r);
    void CardMove(SDL_Rect r);
private:

};

#endif	/* MOUSE_H */
