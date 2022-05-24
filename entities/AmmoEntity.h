//
// Created by nstan on 24/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_AMMOENTITY_H
#define OOP_S1_2022_MAJOR_PRAC_AMMOENTITY_H

#include <string>
#include "Entity.h"

using namespace std;
class AmmoEntity: public Entity {
protected:
    sf::Texture ammoTexture;
    sf::Sprite ammoSprite;
    long ammoQuantity;
    AmmoEntity(sf::RenderWindow* window, const string& textureFile, long ammoQuantity);
public:
    void update(float delta) override;
    void render(float delta, float camX, float camY) override;

    long getAmmoQuantity() const;
};


#endif //OOP_S1_2022_MAJOR_PRAC_AMMOENTITY_H
