//
// Created by nstan on 17/05/2022.
//
#include <string>
#include <fstream>
#include <sstream>
#include "TileMapLevel.h"
#include "../engine/GameConstants.h"


TileMapLevel::TileMapLevel(string levelFileName, sf::RenderWindow *window,
                           int tileMapTextureUnit) : tiles() {
    fstream levelFile(levelFileName, ios::in);
    string line, tileType;
    int row = 0, col = 0;
    if (levelFile.is_open()) {
        while (getline(levelFile, line)) {
            stringstream str(line);
            while (getline(str, tileType, ',')) {
                auto* tile = new TileEntity(window, stoi(tileType), tileMapTextureUnit);
                tile->setPosition(col*(tileMapTextureUnit*GAME_SCALE), row*(tileMapTextureUnit*GAME_SCALE));
                tiles.push_back(tile);
                col++;
            }
            col = 0;
            row++;
        }
    }

}

TileMapLevel::~TileMapLevel() {
    for (auto tile : tiles) {
        delete tile;
    }
}

void TileMapLevel::render(EntityRenderer *renderer) {
    for (auto tile : tiles) {
        renderer->renderEntity(tile);
    }
}
