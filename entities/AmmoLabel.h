//
// Created by nstan on 23/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_AMMOLABEL_H
#define OOP_S1_2022_MAJOR_PRAC_AMMOLABEL_H


#include "Entity.h"

class AmmoLabel: public Entity {
protected:
    long* ammo;
    sf::Font font;
    sf::Text text;
public:
    AmmoLabel(sf::RenderWindow *window, long *ammo);

    void update(float delta) override;

    void render(float delta, float camX, float camY) override;

};


#endif //OOP_S1_2022_MAJOR_PRAC_AMMOLABEL_H
