//
// Created by nstan on 17/05/2022.
//

#ifndef SCREENLABELENTITY_H
#define SCREENLABELENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"

using namespace std;

class ScreenLabelEntity: public Entity {
protected:
    sf::Texture titleScreenTexture;
    sf::Sprite titleScreenSprite;
    float r,g,b;
    float colourIncrement;
    bool countDown = false;
public:
    ScreenLabelEntity(sf::RenderWindow *window, string fileName);
    void update(float delta) override;
    void render(float delta, float camX, float camY) override;

};


#endif //SCREENLABELENTITY_H
