//
// Created by nstan on 9/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_GREENCIRCLEENTITY_H
#define OOP_S1_2022_MAJOR_PRAC_GREENCIRCLEENTITY_H


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


#endif //OOP_S1_2022_MAJOR_PRAC_GREENCIRCLEENTITY_H
