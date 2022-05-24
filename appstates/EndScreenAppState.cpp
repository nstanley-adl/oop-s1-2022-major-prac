//
// Created by nstan on 17/05/2022.
//

#include "EndScreenAppState.h"

EndScreenAppState::EndScreenAppState(sf::RenderWindow *window, EntityRenderer *renderer, long* score) : AppState(window,
                                                                                                        renderer),
                                                                                           labelEntity(window,
                                                                                                       "../res/over.png"),
                                                                                               level("../res/title_level.csv", window, 16), text(), font(), score(score) {
    font.loadFromFile("../res/Pixellari.ttf");
    text.setPosition(400,450);
    text.setFont(font);
    text.setCharacterSize(64);

}


void EndScreenAppState::onEnable() {
    labelEntity.resetColour();
}

void EndScreenAppState::onDisable() {

}

void EndScreenAppState::update(float delta, float camX, float camY) {
    text.setString("Score: " + to_string(*score));
}

void EndScreenAppState::render(float delta, float camX, float camY) {
//    level.render(renderer);
    renderer->renderEntity(&labelEntity);
    window->draw(text);
}

