//
// Created by nstan on 17/05/2022.
//

#include "TitleScreenAppState.h"

TitleScreenAppState::TitleScreenAppState(sf::RenderWindow *window, EntityRenderer *renderer) : AppState(window,
                                                                                                        renderer),
                                                                                               labelEntity(window,
                                                                                                           "../res/title.png"),
                                                                                               level("../res/title_level.csv", window, 16) {

}


void TitleScreenAppState::onEnable() {
    labelEntity.resetColour();
}

void TitleScreenAppState::onDisable() {

}

void TitleScreenAppState::update(float delta, float camX, float camY) {

}

void TitleScreenAppState::render(float delta, float camX, float camY) {
//    level.render(renderer);
    renderer->renderEntity(&labelEntity);
}

