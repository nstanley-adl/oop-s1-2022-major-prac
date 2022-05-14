//
// Created by nstan on 9/05/2022.
//

#ifndef TESTAPPSTATE_H
#define TESTAPPSTATE_H


#include "AppState.h"
#include "GreenCircleEntity.h"

class TestAppState: public AppState {
protected:
    GreenCircleEntity* circleEntity;
public:
    TestAppState(sf::RenderWindow* window, EntityRenderer* renderer);
    ~TestAppState();

public:
    void onEnable() override;
    void onDisable() override;
    void update(float delta) override;
    void render(float delta) override;
};


#endif //TESTAPPSTATE_H
