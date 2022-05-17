//
// Created by nstan on 7/05/2022.
//

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.h"

Entity::Entity(sf::RenderWindow* window): window(window) {
    position = new sf::Vector2<float>(0,0);
}

Entity::~Entity() {
    delete position;
}

float Entity::getXPosition() {
    return position->x;
}

float Entity::getYPosition() {
    return position->y;
}

void Entity::setPosition(float x, float y) {
    position->x = x;
    position->y = y;
}

void Entity::setXPosition(float x) {
    position->x = x;
}

void Entity::setYPosition(float y) {
    position->y = y;
}



