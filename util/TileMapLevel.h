//
// Created by nstan on 17/05/2022.
//

#ifndef TILEMAPLEVEL_H
#define TILEMAPLEVEL_H
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "../entities/TileEntity.h"
#include "../engine/EntityRenderer.h"

using namespace std;

class TileMapLevel {
protected:
    vector<TileEntity*> tiles;
public:
    TileMapLevel(string levelFileName, sf::RenderWindow *window,
                 int tileMapTextureUnit);
    void render(EntityRenderer* renderer);
    ~TileMapLevel();
};


#endif //TILEMAPLEVEL_H
