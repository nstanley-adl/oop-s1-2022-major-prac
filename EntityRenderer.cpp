//
// Created by nstan on 7/05/2022.
//

#include <iostream>
#include <stdexcept>
#include "EntityRenderer.h"

using namespace std;

EntityRenderer::EntityRenderer(sf::RenderWindow *window) {
    this->window = window;
    numOfEntities = 0;
}

void EntityRenderer::preRender() {
    window->clear();
}

void EntityRenderer::render(float delta) {
    for (int i = 0; i < numOfEntities; i++) {
        entities[i]->render(delta);
    }
}

void EntityRenderer::postRender() {
    window->display();
    numOfEntities = 0;
}

void EntityRenderer::renderEntity(Entity *entity) {
    if (numOfEntities < MAX_ENTITIES) {
        entities[numOfEntities] = entity;
        numOfEntities++;
    }  else throw std::length_error("Attempt to render too many entities, oh no!");
}
