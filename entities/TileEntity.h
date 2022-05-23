//
// Created by nstan on 14/05/2022.
//

#ifndef TILEENTITY_H
#define TILEENTITY_H
#include "Entity.h"
#include <SFML/Graphics.hpp>

class TileEntity: public Entity {
protected:
    sf::Sprite* tileSprite;
    static sf::Texture tileMapTexture;
    static bool textureLoaded;
public:
    TileEntity(sf::RenderWindow *window, int textureX, int tileMapTextureUnit);

    void update(float delta) override;

    void render(float delta, float camX, float camY) override;

    virtual ~TileEntity();

};


#endif //TILEENTITY_H
