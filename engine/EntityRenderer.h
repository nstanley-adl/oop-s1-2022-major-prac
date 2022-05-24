//
// Created by nstan on 7/05/2022.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "../entities/Entity.h"

using namespace std;

class EntityRenderer {
protected:
    sf::RenderWindow* window;
    vector<Entity*> entities;
    float* camX;
    float* camY;
    float baseSpeed;
public:
    EntityRenderer(sf::RenderWindow *window, float *camX, float *camY);
    void preRender();
    void render(float delta);
    void postRender();
    void renderEntity(Entity* entity);

    void update(float delta);
};


#endif //RENDERER_H
