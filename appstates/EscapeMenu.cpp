//
// Created by nstan on 24/05/2022.
//

#include "EscapeMenu.h"
#include <iostream>

using namespace std;

EscapeMenu::EscapeMenu(sf::RenderWindow *window, EntityRenderer *renderer) : AppState(window, renderer), selectedOption(0), optionText(), font(), options({"continue", "high scores", "exit"}), selectionChangeCoolDown(), menuResult(CONTINUE) {
    font.loadFromFile("../res/Pixellari.ttf");
    for (int i = 0; i < options.size(); i++) {
        optionText.push_back(new sf::Text());
    }


    float yPos = 100;
    for (auto text : optionText) {
        text->setFont(font);
        text->setPosition(100, yPos);
        text->setFillColor(sf::Color::White);
        text->setCharacterSize(60);
        text->setString("SAMPLE");
        yPos += 100;
    }
}

void EscapeMenu::onEnable() {
    selectedOption = 0;
}

void EscapeMenu::onDisable() {

}

void EscapeMenu::update(float delta, float camX, float camY) {
    if (selectionChangeCoolDown.getElapsedTime().asSeconds() > 0.2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            selectionChangeCoolDown.restart();
            if (selectedOption+1 < options.size()) selectedOption++;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            selectionChangeCoolDown.restart();
            if (selectedOption-1 >=0) selectedOption--;
        }
    }
    switch (selectedOption) {
        case 0: // continue
            menuResult = CONTINUE;
            break;
        case 1: // high scores
            menuResult = VIEW_HIGH_SCORES;
            break;
        case 2: // exitGame
            menuResult = EXIT_GAME;
            break;
    }

}

void EscapeMenu::render(float delta, float camX, float camY) {
    for (int i = 0; i < options.size(); i++) {
        if (i == selectedOption) {
            optionText.at(i)->setString(options.at(i) + " <");
        } else {
            optionText.at(i)->setString(options.at(i));
        }
        window->draw(*(optionText.at(i)));
    }

}

MenuOption EscapeMenu::getMenuResult() const {
    return menuResult;
}


