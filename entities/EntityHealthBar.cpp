//
// Created by nstan on 17/05/2022.
//

#include "EntityHealthBar.h"

EntityHealthBar::EntityHealthBar(sf::RenderWindow *window, DamageableEntity *entityFor, const sf::Vector2f &offsetFromEntityPosition):Entity(window), entityFor(entityFor), offsetFromEntityPosition(offsetFromEntityPosition),
                                                                                                                                      backgroundRect(),
                                                                                                                                      healthRect() {
    backgroundRect.setFillColor(sf::Color(127, 127, 127, 100));
    backgroundRect.setSize(sf::Vector2f(HEALTH_BAR_WIDTH, HEALTH_BAR_HEIGHT));
    healthRect.setFillColor(sf::Color(0,255,0,100));
    healthRect.setSize(sf::Vector2f(HEALTH_BAR_WIDTH, HEALTH_BAR_HEIGHT));
}

void EntityHealthBar::update(float delta) {
    healthRect.setSize(sf::Vector2f(HEALTH_BAR_WIDTH*entityFor->getHealthAsDecimal(), HEALTH_BAR_HEIGHT));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        entityFor->damage(1);
}

void EntityHealthBar::render(float delta, float camX, float camY) {
    healthRect.setPosition(entityFor->getXPosition()-camX-offsetFromEntityPosition.x, entityFor->getYPosition()-camY-offsetFromEntityPosition.y);
    backgroundRect.setPosition(entityFor->getXPosition()-camX-offsetFromEntityPosition.x, entityFor->getYPosition()-camY-offsetFromEntityPosition.y);
    window->draw(backgroundRect);
    window->draw(healthRect);
}

