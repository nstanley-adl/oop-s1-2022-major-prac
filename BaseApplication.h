//
// Created by nstan on 7/05/2022.
//

#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H
#include <SFML/Graphics.hpp>
#include "GameConstants.h"
#include "AppState.h"
#include "EntityRenderer.h"


const int MAX_TRACKED_APP_STATES = 35;

class BaseApplication {
protected:
    bool isRunning;
    EntityRenderer* renderer;
    sf::RenderWindow* window;
    sf::Clock deltaClock;
    float deltaTime;
    int numberOfAppStates;
    AppState* appStates[MAX_TRACKED_APP_STATES]{};

    virtual void initialise() = 0;
    virtual void update(float delta) = 0;
    virtual void render(float delta) = 0;
public:
    BaseApplication();
    void run();
    void exit();
    void trackAppState(AppState* appStateToTrack);

    EntityRenderer *getRenderer() const;
    sf::RenderWindow *getWindow() const;

//    bool checkKeyPress()
//    void addAppState(AppState* state);
//    void removeAppState(AppState* state);
    ~BaseApplication();
};


#endif //GAMEAPPLICATION_H
