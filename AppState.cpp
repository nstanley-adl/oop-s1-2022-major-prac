//
// Created by nstan on 7/05/2022.
//

#include "AppState.h"

AppState::AppState(sf::RenderWindow* renderWindow, EntityRenderer* entityRenderer): window(renderWindow), renderer(entityRenderer) {
    enabled = false;
}

void AppState::enable() {
    enabled = true;
    onEnable();
}

void AppState::disable() {
    enabled = false;
    onDisable();
}

bool AppState::isEnabled() {
    return enabled;
}
