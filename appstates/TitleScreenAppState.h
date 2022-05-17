//
// Created by nstan on 17/05/2022.
//

#ifndef TITLESCREENAPPSTATE_H
#define TITLESCREENAPPSTATE_H


#include "AppState.h"
#include "../util/TileMapLevel.h"
#include "../entities/ScreenLabelEntity.h"

class TitleScreenAppState: public AppState {
protected:
    TileMapLevel level;
    ScreenLabelEntity labelEntity;
public:
    TitleScreenAppState(sf::RenderWindow *window, EntityRenderer *renderer);

    void onEnable() override;
    void onDisable() override;
    void update(float delta) override;
    void render(float delta) override;

};


#endif //TITLESCREENAPPSTATE_H
