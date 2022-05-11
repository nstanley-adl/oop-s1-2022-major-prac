//
// Created by nstan on 7/05/2022.
//

#include "AppState.h"

AppState::AppState(sf::RenderWindow* renderWindow, EntityRenderer* entityRenderer): window(renderWindow), renderer(entityRenderer) {
    isEnabled = false;
}

void AppState::enable() {
    isEnabled = true;
    onEnable();
}

void AppState::disable() {
    isEnabled = false;
    onDisable();
}
