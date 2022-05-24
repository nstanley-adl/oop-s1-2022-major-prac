//
// Created by nstan on 17/05/2022.
//

#include "Monster.h"
#include <cmath>
#include <string>
#include "../engine/GameConstants.h"

using namespace std;

Monster::Monster(sf::RenderWindow *window) : Monster(window, 200, "../res/baddie.png", 250) {}

Monster::Monster(sf::RenderWindow *window, float maxHealth, const string& textureFile, int maxStep) : DamageableEntity(window, maxHealth), monsterSprite(), pathFindStepSize(45+(rand() % (maxStep-45+1))) {
    monsterTexture.loadFromFile(textureFile);
    monsterTexture.setSmooth(false);
    monsterSprite.setTexture(monsterTexture);
    monsterSprite.setScale(GAME_SCALE, GAME_SCALE);
}


void Monster::update(float delta) {

}

void Monster::render(float delta, float camX, float camY) {
    float deltaStepSize = (pathFindStepSize) * delta;
    float targetX = camX+(WINDOW_WIDTH/2)-PLAYER_RADIUS; //centre of the screen
    float targetY = camY+(WINDOW_HEIGHT/2)-PLAYER_RADIUS; //centre of the screen ;)
    if (abs(getXPosition() - targetX) > 20) {
        if (abs((getXPosition() - deltaStepSize)-targetX) < abs((getXPosition() + deltaStepSize)-targetX)) {
            setXPosition(getXPosition() - deltaStepSize);
        } else {
            setXPosition(getXPosition() + deltaStepSize);
        }
    }
    if (abs(getYPosition() - targetY) > 20) {
        if (abs((getYPosition() - deltaStepSize)-targetY) < abs((getYPosition() + deltaStepSize)-targetY)) {
            setYPosition(getYPosition() - deltaStepSize);
        } else {
            setYPosition(getYPosition() + deltaStepSize);
        }
    }

    monsterSprite.setPosition(getXPosition()-camX, getYPosition()-camY);
    window->draw(monsterSprite);

}

