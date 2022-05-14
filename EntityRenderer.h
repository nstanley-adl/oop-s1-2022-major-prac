//
// Created by nstan on 7/05/2022.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

const int MAX_ENTITIES = 500;

class EntityRenderer {
protected:
    sf::RenderWindow* window;
    Entity* entities[MAX_ENTITIES]{};
    int numOfEntities;
public:
    EntityRenderer(sf::RenderWindow* window);
    void preRender();
    void render(float delta);
    void postRender();
    void renderEntity(Entity* entity);

    void update(float delta);
};


#endif //RENDERER_H
