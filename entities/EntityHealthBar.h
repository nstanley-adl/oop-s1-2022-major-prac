//
// Created by nstan on 17/05/2022.
//

#ifndef ENTITYHEALTHBAR_H
#define ENTITYHEALTHBAR_H


#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "DamageableEntity.h"

const int HEALTH_BAR_HEIGHT = 20;
const int HEALTH_BAR_WIDTH = 200;

class EntityHealthBar: public Entity {
protected:
    DamageableEntity* entityFor;
    sf::Vector2f offsetFromEntityPosition;
    sf::RectangleShape backgroundRect;
    sf::RectangleShape healthRect;
public:
    EntityHealthBar(sf::RenderWindow *window, DamageableEntity *entityFor,
                    const sf::Vector2f &offsetFromEntityPosition);

    void update(float delta) override;

    void render(float delta, float camX, float camY) override;
};


#endif //ENTITYHEALTHBAR_H
