//
// Created by nstan on 9/05/2022.
//

#ifndef GREENCIRCLEENTITY_H
#define GREENCIRCLEENTITY_H


#include "Entity.h"
#include "DamageableEntity.h"

class PlayerEntity: public DamageableEntity {
protected:
    sf::Texture* playerTexture;
    sf::Sprite* playerSprite;
    float prevCamY;
public:
    PlayerEntity(sf::RenderWindow* window);
    void update(float delta) override;
    void render(float delta, float camX, float camY) override;

    virtual ~PlayerEntity();

};


#endif //GREENCIRCLEENTITY_H
