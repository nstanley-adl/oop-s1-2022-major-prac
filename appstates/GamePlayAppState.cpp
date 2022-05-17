//
// Created by nstan on 9/05/2022.
//

#include "GamePlayAppState.h"

void GamePlayAppState::onEnable() {

}

void GamePlayAppState::onDisable() {

}

void GamePlayAppState::update(float delta) {

}

void GamePlayAppState::render(float delta) {
    level->render(renderer);
    for (auto monster : monsters) {
        renderer->renderEntity(monster);
    }
    renderer->renderEntity(playerEntity);
}

GamePlayAppState::~GamePlayAppState() {
    for (auto monster: monsters) {
        delete monster;
    }
    delete playerEntity;
    delete level;
}

GamePlayAppState::GamePlayAppState(sf::RenderWindow *window, EntityRenderer *renderer) : AppState(window, renderer), monsters() {
    playerEntity = new PlayerEntity(window);
    level = new TileMapLevel("../res/level1.csv", window, 16);
    for (int i = 0; i < 10; i++) {
        auto* monster = new Monster(window, 200);
        monster->setPosition(300+(std::rand()%(1000-300+1)), 300+(std::rand()%(1000-300+1)));
        monsters.push_back(monster);
    }
}
