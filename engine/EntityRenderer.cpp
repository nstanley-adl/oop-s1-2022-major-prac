//
// Created by nstan on 7/05/2022.
//

#include <stdexcept>
#include "EntityRenderer.h"

using namespace std;

EntityRenderer::EntityRenderer(sf::RenderWindow *window, float *camX, float *camY)
        : entities(), baseSpeed(600), camX(camX), camY(camY) {
    this->window = window;

}

void EntityRenderer::update(float delta) {
    float speed = baseSpeed * delta;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // strafe up left
        *camY -= speed/2.f;
        *camX -= speed/2.f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // strafe down left
        *camY += speed/2.f;
        *camX -= speed/2.f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // strafe down right
        *camY += speed/2.f;
        *camX += speed/2.f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { // strafe up right
        *camY -= speed/2.f;
        *camX += speed/2.f;
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            *camY-= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            *camX -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            *camY += speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            *camX += speed;
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
        (*i)->render(delta, *camX, *camY);
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
