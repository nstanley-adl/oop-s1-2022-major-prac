//
// Created by nstan on 9/05/2022.
//

#include "PlayerEntity.h"
#include "../engine/GameConstants.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;



PlayerEntity::PlayerEntity(sf::RenderWindow* window) : DamageableEntity(window, 200.f), prevCamY() {
    playerTexture = new sf::Texture();
    playerTexture->loadFromFile("../res/player.png");
    playerSprite = new sf::Sprite();
    playerSprite->setTexture(*playerTexture);
    playerSprite->setTextureRect(sf::IntRect(0,0,16,16));
    playerSprite->setScale(9.f, 9.f);
}

void PlayerEntity::render(float delta, float camX, float camY) {
    setPosition(camX+(WINDOW_WIDTH/2)-PLAYER_RADIUS, camY+(WINDOW_HEIGHT/2)-PLAYER_RADIUS);
    playerSprite->setPosition((WINDOW_WIDTH/2)-PLAYER_RADIUS, (WINDOW_HEIGHT/2)-PLAYER_RADIUS);
    if (camY < prevCamY) {
        playerSprite->setTextureRect(sf::IntRect(16,0,16,16));
    } else
        playerSprite->setTextureRect(sf::IntRect(0,0,16,16));
    window->draw(*playerSprite);
}

void PlayerEntity::update(float delta) {

}

PlayerEntity::~PlayerEntity() {
    delete playerSprite;
    delete playerTexture;
}

