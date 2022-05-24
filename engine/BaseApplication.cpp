//
// Created by nstan on 7/05/2022.
//

#include <SFML/Graphics.hpp>
#include "BaseApplication.h"
#include "../util/GentleAssert.h"


BaseApplication::BaseApplication(): appStates(), isRunning(false), deltaTime(0.f), enterPressed(false), escapePressed(false), playerInput() {
    camX = new float(0);
    camY = new float(0);
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "a1850484 - Practical Project", sf::Style::Close | sf::Style::Titlebar);
    window->setVerticalSyncEnabled(true);
    renderer = new EntityRenderer(window, camX, camY);
}

void BaseApplication::run() {
    isRunning = true;
    initialise();
    deltaClock.restart();
    while (isRunning && window->isOpen()) {
        deltaTime = deltaClock.restart().asSeconds();
        sf::Event event;
        update(deltaTime, *camX, *camY);
        render(deltaTime, *camX, *camY);
        renderer->preRender();
        for (auto i = appStates.begin(); i != appStates.end(); i++) {
            if ((*i)->isEnabled()) {
                gentle_assert((*i)->isEnabled());
                (*i)->update(deltaTime, *camX, *camY);
                (*i)->render(deltaTime, *camX, *camY);
            }
        }
        renderer->update(deltaTime);
        renderer->render(deltaTime);
        renderer->postRender();
        escapePressed = false;
        enterPressed = false;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                exit();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    escapePressed = true;
                if (event.key.code == sf::Keyboard::Enter)
                    enterPressed = true;
            }
            if (event.type == sf::Event::TextEntered) {
                if (isalnum(event.text.unicode)) {
                    playerInput += event.text.unicode;
                }
                if (event.text.unicode == 8 && playerInput.size() > 0) {
                    playerInput.pop_back();
                }
            }
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



