#ifndef __GAMECONTROL_H__
    #define __GAMECONTROL_H__

#include "GameObject.h"
#include <stack>
#include "Event.h"

class GameControl{
public:
    GameControl();
    bool isRunning();

public:
    virtual void Run();
    virtual void Update();
    virtual void RequestInteraction(GameObject*);
    virtual void ReceiveToInteraction(GameObject*);

protected:
    Event*  event;
    bool    Running;
    void*   system;
    int     state;
    std::stack<GameObject*> InteractFrom;
    std::stack<GameObject*> InteractTo;
    virtual void ManageEvents();
    virtual void ManageCollisions();
    virtual void ManageInteractions();
};

#endif
