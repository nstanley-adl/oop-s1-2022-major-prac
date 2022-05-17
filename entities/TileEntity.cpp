//
// Created by nstan on 14/05/2022.
//

#include <SFML/Graphics.hpp>
#include "TileEntity.h"
#include "../engine/GameConstants.h"

sf::Texture TileEntity::tileMapTexture = sf::Texture();
bool TileEntity::textureLoaded = false;

TileEntity::TileEntity(sf::RenderWindow *window, int textureX, int tileMapTextureUnit)
        : Entity(window) {
    if (!textureLoaded) {
        tileMapTexture.loadFromFile("../res/tilemap.png");
        tileMapTexture.setSmooth(false);
        textureLoaded = true;
    }
    tileSprite = new sf::Sprite();
    tileSprite->setTexture(tileMapTexture);
    tileSprite->setScale(GAME_SCALE, GAME_SCALE);
    tileSprite->setTextureRect(sf::IntRect(textureX * tileMapTextureUnit, 0, tileMapTextureUnit, tileMapTextureUnit));

}

void TileEntity::update(float delta) {

}

void TileEntity::render(float delta, float camX, float camY) {
    tileSprite->setPosition(getXPosition() - camX, getYPosition() - camY);
    window->draw(*tileSprite);
}
