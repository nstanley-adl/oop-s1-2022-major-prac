//
// Created by nstan on 24/05/2022.
//

#include <string>
#include "ScoreLabel.h"

using namespace std;

ScoreLabel::ScoreLabel(sf::RenderWindow *window, long *score) : Entity(window), score(score) {
    font.loadFromFile("../res/Pixellari.ttf");
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(25, 100);
}

void ScoreLabel::update(float delta) {
    text.setString("score: " + to_string(*score));
}

void ScoreLabel::render(float delta, float camX, float camY) {
    window->draw(text);
}
