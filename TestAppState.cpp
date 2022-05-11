//
// Created by nstan on 9/05/2022.
//

#include "TestAppState.h"


void TestAppState::onEnable() {

}

void TestAppState::onDisable() {

}

void TestAppState::update(float delta) {

}

void TestAppState::render(float delta) {
    renderer->renderEntity(circleEntity);
}

TestAppState::~TestAppState() {
    delete circleEntity;
}

TestAppState::TestAppState(sf::RenderWindow *window, EntityRenderer *renderer) : AppState(window, renderer) {
    circleEntity = new GreenCircleEntity(window);
}
