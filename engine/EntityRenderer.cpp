//
// Created by nstan on 7/05/2022.
//

#include <stdexcept>
#include "EntityRenderer.h"

using namespace std;

EntityRenderer::EntityRenderer(sf::RenderWindow *window): entities(), cameraPosition(), baseSpeed(400) {
    this->window = window;
}

void EntityRenderer::update(float delta) {
    float speed = baseSpeed * delta;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // strafe up left
        cameraPosition.y -= speed/2.f;
        cameraPosition.x -= speed/2.f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // strafe down left
        cameraPosition.y += speed/2.f;
        cameraPosition.x -= speed/2.f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // strafe down right
        cameraPosition.y += speed/2.f;
        cameraPosition.x += speed/2.f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { // strafe up right
        cameraPosition.y -= speed/2.f;
        cameraPosition.x += speed/2.f;
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            cameraPosition.y -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            cameraPosition.x -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            cameraPosition.y += speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            cameraPosition.x += speed;
    }

//

    for (auto i = entities.begin(); i < entities.end(); i++) {
        (*i)->update(delta);
    }

}

void EntityRenderer::preRender() {
    window->clear();
}

void EntityRenderer::render(float delta) {
    for (auto i = entities.begin(); i < entities.end(); i++) {
        (*i)->render(delta, cameraPosition.x, cameraPosition.y);
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
