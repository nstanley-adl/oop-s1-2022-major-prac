//
// Created by nstan on 17/05/2022.
//

#ifndef ENDSCREENAPPSTATE_H
#define ENDSCREENAPPSTATE_H


#include "AppState.h"
#include "../util/TileMapLevel.h"
#include "../entities/ScreenLabelEntity.h"

class EndScreenAppState: public AppState {
protected:
    TileMapLevel level;
    ScreenLabelEntity labelEntity;
public:
    EndScreenAppState(sf::RenderWindow *window, EntityRenderer *renderer);

    void onEnable() override;
    void onDisable() override;
    void update(float delta) override;
    void render(float delta) override;

};


#endif //ENDSCREENAPPSTATE_H
