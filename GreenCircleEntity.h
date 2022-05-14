//
// Created by nstan on 9/05/2022.
//

#ifndef GREENCIRCLEENTITY_H
#define GREENCIRCLEENTITY_H


#include "Entity.h"

class GreenCircleEntity: public Entity {
protected:
    sf::CircleShape* circleShape;
public:
    GreenCircleEntity(sf::RenderWindow* window);
    void update(float delta) override;
    void render(float delta) override;

    virtual ~GreenCircleEntity();

};


#endif //GREENCIRCLEENTITY_H
