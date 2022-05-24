//
// Created by nstan on 17/05/2022.
//

#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/Graphics.hpp>
#include "DamageableEntity.h"
#include <string>

using namespace std;

class Monster: public DamageableEntity {
protected:
    sf::Texture monsterTexture;
    sf::Sprite monsterSprite;
    float pathFindStepSize;
    Monster(sf::RenderWindow *window, float maxHealth, const string& textureFile, int maxStep);
public:
    Monster(sf::RenderWindow *window);
    void update(float delta) override;
    void render(float delta, float camX, float camY) override;
};


#endif //MONSTER_H
