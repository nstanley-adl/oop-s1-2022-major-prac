//
// Created by nstan on 7/05/2022.
//

#ifndef APPLICATIONSTATE_H
#define APPLICATIONSTATE_H

#include "EntityRenderer.h"

class AppState {
protected:
    bool isEnabled;
    sf::RenderWindow* window;
    EntityRenderer* renderer;
public:
    AppState(sf::RenderWindow* window, EntityRenderer* renderer);
    void enable();
    void disable();
    virtual void onEnable() = 0;
    virtual void onDisable() = 0;
    virtual void update(float delta) = 0;
    virtual void render(float delta) = 0;
};


#endif //APPLICATIONSTATE_H
