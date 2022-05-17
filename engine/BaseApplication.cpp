//
// Created by nstan on 7/05/2022.
//

#include <SFML/Graphics.hpp>
#include "BaseApplication.h"
#include "../util/GentleAssert.h"


BaseApplication::BaseApplication(): appStates(), isRunning(false), deltaTime(0.f) {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "a1850484 - Practical Project", sf::Style::Close | sf::Style::Titlebar);
    window->setVerticalSyncEnabled(true);
    renderer = new EntityRenderer(window);
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
        for (auto i = appStates.begin(); i != appStates.end(); i++) {
            if ((*i)->isEnabled()) {
                gentle_assert((*i)->isEnabled());
                (*i)->update(deltaTime);
                (*i)->render(deltaTime);
            }
        }
        renderer->update(deltaTime);
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
    appStates.push_back(appStateToTrack);
}



