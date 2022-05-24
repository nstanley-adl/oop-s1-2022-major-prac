//
// Created by nstan on 14/05/2022.
//

#include "DamageableEntity.h"

DamageableEntity::DamageableEntity(sf::RenderWindow *window, float maxHealth) : Entity(window), maxHealth(maxHealth), health(maxHealth) {}

void DamageableEntity::heal(float amount) {
    if (health + amount > maxHealth) health = maxHealth;
    else health += amount;
}

void DamageableEntity::damage(float amount) {
    if (health - amount < 0) health = 0;
    else health -=  amount;
}

float DamageableEntity::getHealth() {
    return health;
}



bool DamageableEntity::isDead() {
    return health == 0;
}

float DamageableEntity::getHealthAsDecimal() {
    return health/maxHealth;
}

float DamageableEntity::getMaxHealth() const {
    return maxHealth;
}


