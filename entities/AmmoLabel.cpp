//
// Created by nstan on 23/05/2022.
//

#include "AmmoLabel.h"
#include <string>

using namespace std;

AmmoLabel::AmmoLabel(sf::RenderWindow *window, long *ammo) : Entity(window), ammo(ammo), font(), text() {
    font.loadFromFile("../res/Pixellari.ttf");
    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);
    text.setPosition(25, 25);
}

void AmmoLabel::update(float delta) {
    text.setString(to_string(*ammo) + " rounds");
}

void AmmoLabel::render(float delta, float camX, float camY) {
    window->draw(text);
}
