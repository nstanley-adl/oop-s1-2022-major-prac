//
// Created by nstan on 7/05/2022.
//

#include <iostream>
#include <stdexcept>
#include "EntityRenderer.h"

using namespace std;

EntityRenderer::EntityRenderer(sf::RenderWindow *window): entities() {
    this->window = window;
}

void EntityRenderer::update(float delta) {
    for (auto i = entities.begin(); i < entities.end(); i++) {
        (*i)->update(delta);
    }
}

void EntityRenderer::preRender() {
    window->clear();
}

void EntityRenderer::render(float delta) {
    for (auto i = entities.begin(); i < entities.end(); i++) {
        (*i)->render(delta);
    }
}

void EntityRenderer::postRender() {
    window->display();
    entities.clear();
//    gentle_assert(entities.empty());
}

void EntityRenderer::renderEntity(Entity *entity) {
    entities.push_back(entity);
}
