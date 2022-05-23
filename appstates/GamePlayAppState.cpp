//
// Created by nstan on 9/05/2022.
//

#include <iostream>
#include "GamePlayAppState.h"
#include "../engine/GameConstants.h"
#include "../entities/AmmoLabel.h"

using namespace std;

void GamePlayAppState::onEnable() {

}

void GamePlayAppState::onDisable() {

}

void GamePlayAppState::update(float delta) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && coolDownClock.getElapsedTime().asSeconds() >= 0.1 && ammo > 0) {
        bulletStream->setHidden(false);
        bulletStream->setEndPoint(sf::Mouse::getPosition(*window));
        bulletStreamClock.restart();
        coolDownClock.restart();
        ammo--;
        for (auto* monster : monsters) {
            if (bulletStream->checkCollision(*(monster->getPosition()), true)) {
                monster->damage(20);
            }
        }
    } else if (bulletStreamClock.getElapsedTime().asSeconds() >= 0.05) {
        bulletStream->setHidden(true);
    }

}

void GamePlayAppState::render(float delta) {
    level->render(renderer);
    for (auto monster : monsters) {
        renderer->renderEntity(monster);
    }
    for (auto healthBar : healthBars) {
        renderer->renderEntity(healthBar);
    }
    renderer->renderEntity(bulletStream);
    renderer->renderEntity(playerEntity);
    renderer->renderEntity(ammoLabel);
}

GamePlayAppState::~GamePlayAppState() {
    for (auto monster: monsters) {
        delete monster;
    }
    for (auto healthBar : healthBars) {
        delete healthBar;
    }
    delete bulletStream;
    delete playerEntity;
    delete ammoLabel;
    delete level;
}

GamePlayAppState::GamePlayAppState(sf::RenderWindow *window, EntityRenderer *renderer) : AppState(window, renderer), monsters(), healthBars(), bulletStreamClock(), ammo(9999) {
    playerEntity = new PlayerEntity(window);
    bulletStream = new BulletStream(window, sf::Color::Yellow);
    ammoLabel = new AmmoLabel(window, &ammo);
    auto* healthBar = new EntityHealthBar(window, playerEntity, sf::Vector2f(0,2*GAME_SCALE));

    healthBars.push_back(healthBar);
    level = new TileMapLevel("../res/level1.csv", window, 16);
    for (int i = 0; i < 1; i++) {
        auto* monster = new Monster(window, 200);
        monster->setPosition(300+(std::rand()%(1000-300+1)), 300+(std::rand()%(1000-300+1)));
        monsters.push_back(monster);
        healthBar = new EntityHealthBar(window, monster, sf::Vector2f(0,2*GAME_SCALE));
        healthBars.push_back(healthBar);
    }
}

