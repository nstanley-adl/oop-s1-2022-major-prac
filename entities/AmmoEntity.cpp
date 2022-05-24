//
// Created by nstan on 24/05/2022.
//

#include "AmmoEntity.h"
#include "../engine/GameConstants.h"

AmmoEntity::AmmoEntity(sf::RenderWindow *window, const string& textureFile, long ammoQuantity): Entity(window), ammoTexture(), ammoSprite(), ammoQuantity(ammoQuantity) {
    ammoTexture.loadFromFile(textureFile);
    ammoTexture.setSmooth(false);
    ammoSprite.setTexture(ammoTexture);
    ammoSprite.setScale(GAME_SCALE, GAME_SCALE);
}

void AmmoEntity::update(float delta) {

}

void AmmoEntity::render(float delta, float camX, float camY) {
    ammoSprite.setPosition(getXPosition()-camX, getYPosition()-camY);
    window->draw(ammoSprite);
}

long AmmoEntity::getAmmoQuantity() const {
    return ammoQuantity;
}
