#ifndef __GAMECONTROL_H__
    #define __GAMECONTROL_H__

#include "GameObject.h"
#include <vector>
#include "Event.h"

class GameControl{
public:
    GameControl();
    bool isRunning();

public:
    virtual void Run();
    virtual void update();
    virtual void manageEvents();
    virtual void manageCollisions();


    void Test();

protected:
    Event* event;
    bool Running;
    void* system;
};

#endif
