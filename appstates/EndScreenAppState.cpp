//
// Created by nstan on 17/05/2022.
//

#include "EndScreenAppState.h"

EndScreenAppState::EndScreenAppState(sf::RenderWindow *window, EntityRenderer *renderer) : AppState(window,
                                                                                                        renderer),
                                                                                           labelEntity(window,
                                                                                                       "../res/over.png"),
                                                                                               level("../res/title_level.csv", window, 16) {

}


void EndScreenAppState::onEnable() {

}

void EndScreenAppState::onDisable() {

}

void EndScreenAppState::update(float delta) {

}

void EndScreenAppState::render(float delta) {
    level.render(renderer);
    renderer->renderEntity(&labelEntity);
}

