//
// Created by nstan on 14/05/2022.
//

#ifndef DAMAGEABLEENTITY_H
#define DAMAGEABLEENTITY_H


#include "Entity.h"

class DamageableEntity: public Entity {
protected:
    float health;
    float maxHealth;
public:
    DamageableEntity(sf::RenderWindow *window, float maxHealth);
    void heal(float amount);
    void damage(float amount);
    float getHealth();
    bool isDead();
    float getHealthAsDecimal();

    float getMaxHealth() const;
};


#endif //DAMAGEABLEENTITY_H
