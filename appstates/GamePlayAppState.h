//
// Created by nstan on 9/05/2022.
//

#ifndef TESTAPPSTATE_H
#define TESTAPPSTATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "AppState.h"
#include "../entities/PlayerEntity.h"
#include "../entities/TileEntity.h"
#include "../util/TileMapLevel.h"
#include "../entities/EntityHealthBar.h"
#include "../entities/Monster.h"
#include "../entities/BulletStream.h"
#include "../entities/AmmoLabel.h"
#include "../entities/ScoreLabel.h"
#include "../entities/AmmoEntity.h"


using namespace std;

const int STARTING_AMMO = 150;
const int NUM_ENEMIES = 16;

class GamePlayAppState: public AppState {
protected:
    PlayerEntity* playerEntity;
    vector<Monster*> monsters;
    vector<EntityHealthBar*> healthBars;
    vector<AmmoEntity*> ammoBoxes;
    BulletStream* bulletStream;
    sf::Clock bulletStreamClock;
    sf::Clock coolDownClock; // cool down for firing.
    long ammo;
    long* score;
    bool gameOver;
    AmmoLabel* ammoLabel;
    ScoreLabel* scoreLabel;
//    EntityHealthBar playerHealthBar;
    TileMapLevel* level;
private:
    int static getRandomMinusOrPositive();
    void randomizeEntityPosition(Entity* entity, int bias);

    void resetMonster(Monster* monster);
public:
    GamePlayAppState(sf::RenderWindow* window, EntityRenderer* renderer, long* score);
    ~GamePlayAppState();


public:
    void onEnable() override;
    void onDisable() override;
    void update(float delta, float camX, float camY) override;
    void render(float delta, float camX, float camY) override;
    void resetGame();

    long* getScore();



    bool isGameOver() const;
};


#endif //TESTAPPSTATE_H
