//
// Created by nstan on 9/05/2022.
//

#include <iostream>
#include "GamePlayAppState.h"
#include "../entities/BossMonster.h"
#include "../entities/BigAmmoBox.h"
#include "../entities/SmallAmmoBox.h"

using namespace std;

void GamePlayAppState::onEnable() {

}

void GamePlayAppState::onDisable() {

}

void GamePlayAppState::update(float delta, float camX, float camY) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && coolDownClock.getElapsedTime().asSeconds() >= 0.1 && ammo > 0) {
        bulletStream->setHidden(false);
        bulletStream->setEndPoint(sf::Mouse::getPosition(*window));
        bulletStreamClock.restart();
        coolDownClock.restart();
        ammo--;
        for (auto* monster : monsters) {
            sf::Vector2f worldPos = sf::Vector2f(*(monster->getPosition()));
            worldPos.x -= camX - PLAYER_RADIUS;
            worldPos.y -= camY - PLAYER_RADIUS;
            if (bulletStream->checkCollision(worldPos, false)) {
                monster->damage(20);
            }
        }
    } else if (bulletStreamClock.getElapsedTime().asSeconds() >= 0.05) {
        bulletStream->setHidden(true);
    }
    for (auto* monster : monsters) {
        if (monster->isDead()) {
            (*score)++;
            resetMonster(monster);
        } else {
            float distToPlayer = sqrt(pow(playerEntity->getXPosition() - monster->getXPosition(), 2.0) + pow(monster->getYPosition() - playerEntity->getYPosition(), 2.0));
            if (distToPlayer < 40) playerEntity->damage(1);
        }
    }
    if (playerEntity->isDead()) gameOver = true;

    for (auto ammoBox: ammoBoxes) {
        float distToPlayer = sqrt(pow(playerEntity->getXPosition() - ammoBox->getXPosition(), 2.0) + pow(ammoBox->getYPosition() - playerEntity->getYPosition(), 2.0));
        if (distToPlayer < 60) {
            ammo += ammoBox->getAmmoQuantity();
            randomizeEntityPosition(ammoBox, 200);
        }
    }

}

void GamePlayAppState::render(float delta, float camX, float camY) {
    level->render(renderer);
    for (auto monster : monsters) {
        renderer->renderEntity(monster);
    }
    for (auto ammoBox : ammoBoxes) {
        renderer->renderEntity(ammoBox);
    }
    for (auto healthBar : healthBars) {
        renderer->renderEntity(healthBar);
    }
    renderer->renderEntity(bulletStream);
    renderer->renderEntity(playerEntity);
    renderer->renderEntity(ammoLabel);
    renderer->renderEntity(scoreLabel);
}

GamePlayAppState::~GamePlayAppState() {
    for (auto monster: monsters) {
        delete monster;
    }
    for (auto healthBar : healthBars) {
        delete healthBar;
    }
    for (auto ammoBox : ammoBoxes) {
        delete ammoBox;
    }
    delete bulletStream;
    delete playerEntity;
    delete ammoLabel;
    delete scoreLabel;
    delete level;
}

GamePlayAppState::GamePlayAppState(sf::RenderWindow *window, EntityRenderer *renderer, long* score) : AppState(window, renderer), monsters(), healthBars(), ammoBoxes(), bulletStreamClock(), ammo(STARTING_AMMO), score(score), gameOver(false) {
    playerEntity = new PlayerEntity(window);
    bulletStream = new BulletStream(window, sf::Color::Yellow);
    ammoLabel = new AmmoLabel(window, &ammo);
    scoreLabel = new ScoreLabel(window, score);
    auto* healthBar = new EntityHealthBar(window, playerEntity, sf::Vector2f(0,2*GAME_SCALE));

    healthBars.push_back(healthBar);
    level = new TileMapLevel("../res/level2.csv", window, 16);
    for (int i = 0; i < NUM_ENEMIES; i++) {
        Monster* monster;
        if (i <= NUM_ENEMIES/4)
            monster = new BossMonster(window);
        else
            monster = new Monster(window);
        monster->setPosition(300+(std::rand()%(1000-300+1)), 300+(std::rand()%(1000-300+1)));
        monsters.push_back(monster);
        healthBar = new EntityHealthBar(window, monster, sf::Vector2f(0,2*GAME_SCALE));
        healthBars.push_back(healthBar);
    }
    for (int i = 0; i < 10; i++) {
        AmmoEntity* ammoBox;
        int bigBoxProb = rand() % 3;
        if (bigBoxProb == 1)
            ammoBox = new BigAmmoBox(window);
        else
            ammoBox = new SmallAmmoBox(window);
        ammoBox->setPosition((3*WINDOW_WIDTH-(rand()%(3*WINDOW_WIDTH))), (3*WINDOW_HEIGHT-(rand()%(3*WINDOW_HEIGHT))));
        ammoBoxes.push_back(ammoBox);
    }
}

int GamePlayAppState::getRandomMinusOrPositive() {
    if (rand() % 2 == 0)
        return -1;
    return 1;
}

bool GamePlayAppState::isGameOver() const {
    return gameOver;
}

void GamePlayAppState::resetMonster(Monster *monster) {
    monster->heal(monster->getMaxHealth());
    randomizeEntityPosition(monster, 1);
}

void GamePlayAppState::randomizeEntityPosition(Entity* entity, int bias) {
    entity->setPosition((playerEntity->getXPosition()+WINDOW_WIDTH+(rand()%bias))*getRandomMinusOrPositive(), (playerEntity->getYPosition()+WINDOW_HEIGHT+rand()%bias)*getRandomMinusOrPositive());
}

void GamePlayAppState::resetGame() {
    (*score) = 0;
    gameOver = false;
    ammo = STARTING_AMMO;
    playerEntity->heal(playerEntity->getMaxHealth());
    for (auto monster : monsters) {
        resetMonster(monster);
    }
    for (auto ammoBox : ammoBoxes) {
        ammoBox->setPosition((3*WINDOW_WIDTH-(rand()%(3*WINDOW_WIDTH))), (3*WINDOW_HEIGHT-(rand()%(3*WINDOW_HEIGHT))));
    }
}

