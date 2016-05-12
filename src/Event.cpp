#include "Event.h"
#include "Log.h"

Event Event::Instance;
Event::Event(){}

Event* Event::GetInstance() { return &Event::Instance; }

void Event::update(){
    //Cleaning older events
    eventList.clear();
    //Reading new events
    SDL_Event event;
    while(SDL_PollEvent(&event))
        eventList.push_back(event);
}

bool Event::MouseButtonDown(Uint8 button){
    for (SDL_Event ev : eventList)
        if (ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == button)
            return true;
    return false;
}

bool Event::MouseButtonUp(Uint8 button){
    for (SDL_Event ev : eventList)
        if (ev.type == SDL_MOUSEBUTTONUP && ev.button.button == button)
            return true;
    return false;
}

SDL_Point Event::GetMousePos(){
    SDL_Point mouse;
    SDL_GetRelativeMouseState(&mouse.x, &mouse.y);
    return mouse;
}

bool Event::KeyDown(SDL_Keycode keycode){
    for (SDL_Event ev : eventList)
        if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == keycode)
            return true;
    return false;
}

bool Event::KeyUp(SDL_Keycode keycode){
    for (SDL_Event ev : eventList)
        if (ev.type == SDL_KEYUP && ev.key.keysym.sym == keycode)
            return true;
    return false;
}

bool Event::QuitRequest(){
    for (SDL_Event ev : eventList)
        if (ev.type == SDL_QUIT)
            return true;
    return false;
}
