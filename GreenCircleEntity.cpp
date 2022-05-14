//
// Created by nstan on 9/05/2022.
//

#include "GreenCircleEntity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

void GreenCircleEntity::render(float delta) {
    window->draw(*circleShape);
}

GreenCircleEntity::GreenCircleEntity(sf::RenderWindow* window) : Entity(window) {
    circleShape = new sf::CircleShape(100.f);
    circleShape->setFillColor(sf::Color::Green);
}

GreenCircleEntity::~GreenCircleEntity() {
    delete circleShape;
}

void GreenCircleEntity::update(float delta) {
    circleShape->setPosition(getXPosition(), getYPosition());
}

