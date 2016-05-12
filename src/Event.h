#ifndef __EVENT_H__
    #define __EVENT_H__

#include <SDL2/SDL.h>
#include <list>

class Event{
private:
    Event();
    static Event Instance;
    std::list<SDL_Event> eventList;
public:
    static Event* GetInstance();
    void update();
    bool MouseButtonDown(Uint8);
    bool MouseButtonUp(Uint8);
    bool KeyDown(SDL_Keycode);
    bool KeyUp(SDL_Keycode);
    bool QuitRequest();
    SDL_Point GetMousePos();
};

#endif
