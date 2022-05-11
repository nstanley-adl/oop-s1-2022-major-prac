//
// Created by nstan on 7/05/2022.
//

#include <SFML/Graphics.hpp>
#include <stdexcept>
#include "BaseApplication.h"


BaseApplication::BaseApplication() {
    isRunning = false;
    deltaTime = 0.f;
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "a1850484 - Practical Project", sf::Style::Close | sf::Style::Titlebar);
    window->setVerticalSyncEnabled(true);
    renderer = new EntityRenderer(window);
    numberOfAppStates = 0;
}

void BaseApplication::run() {
    isRunning = true;
    initialise();
    deltaClock.restart();
    while (isRunning && window->isOpen()) {
        deltaTime = deltaClock.restart().asSeconds();
        sf::Event event;
        update(deltaTime);
        render(deltaTime);
        for (int i = 0; i < numberOfAppStates; i++) {
            appStates[i]->update(deltaTime);
            appStates[i]->render(deltaTime);
        }
        renderer->preRender();
        renderer->render(deltaTime);
        renderer->postRender();
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                exit();
        }
    }
    window->close();
}


void BaseApplication::exit() {
    isRunning = false;
}

BaseApplication::~BaseApplication() {
    delete window;
    delete renderer;
}

EntityRenderer *BaseApplication::getRenderer() const {
    return renderer;
}

sf::RenderWindow *BaseApplication::getWindow() const {
    return window;
}

void BaseApplication::trackAppState(AppState *appStateToTrack) {
    if (numberOfAppStates < MAX_TRACKED_APP_STATES) {
        appStates[numberOfAppStates] = appStateToTrack;
        numberOfAppStates++;
    } else throw std::length_error("Maximum number of AppStates reached!");
}



