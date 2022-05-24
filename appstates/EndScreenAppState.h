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
    sf::Font font;
    sf::Text text;
    long* score;
public:
    EndScreenAppState(sf::RenderWindow *window, EntityRenderer *renderer, long* score);

    void onEnable() override;
    void onDisable() override;
    void update(float delta, float camX, float camY) override;
    void render(float delta, float camX, float camY) override;

};


#endif //ENDSCREENAPPSTATE_H
