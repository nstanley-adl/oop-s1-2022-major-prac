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


using namespace std;

class GamePlayAppState: public AppState {
protected:
    PlayerEntity* playerEntity;
    vector<Monster*> monsters;

//    EntityHealthBar playerHealthBar;
    TileMapLevel* level;
public:
    GamePlayAppState(sf::RenderWindow* window, EntityRenderer* renderer);
    ~GamePlayAppState();

public:
    void onEnable() override;
    void onDisable() override;
    void update(float delta) override;
    void render(float delta) override;
};


#endif //TESTAPPSTATE_H
