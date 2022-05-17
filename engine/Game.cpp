//
// Created by nstan on 9/05/2022.
//

#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(): BaseApplication(), gamePlayAppState(window, renderer), titleScreenAppState(window, renderer),
              endScreenAppState(window, renderer) {
    this->trackAppState(&gamePlayAppState);
    this->trackAppState(&titleScreenAppState);
    this->trackAppState(&endScreenAppState);
    titleScreenAppState.enable();

}

void Game::initialise() {
    cout << "game initialising :)" << endl;
}

void Game::update(float delta) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (titleScreenAppState.isEnabled()) {
            titleScreenAppState.disable();
            gamePlayAppState.enable();
        } else if (endScreenAppState.isEnabled()) {
            endScreenAppState.disable();
            gamePlayAppState.enable();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        if (!endScreenAppState.isEnabled() && gamePlayAppState.isEnabled()) {
            gamePlayAppState.disable();
            endScreenAppState.enable();
        }
    }

    
}

void Game::render(float delta) {

}
