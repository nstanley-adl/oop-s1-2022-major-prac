//
// Created by nstan on 9/05/2022.
//

#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(): BaseApplication(), testAppState(window, renderer) {
    this->trackAppState(&testAppState);
    testAppState.enable();

}

void Game::initialise() {
    cout << "game initialising :)" << endl;
}

void Game::update(float delta) {
    cout << delta << endl;
}

void Game::render(float delta) {

}
