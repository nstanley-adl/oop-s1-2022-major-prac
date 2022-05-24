//
// Created by nstan on 24/05/2022.
//

#include "EnterScore.h"

EnterScore::EnterScore(sf::RenderWindow *window, EntityRenderer *renderer, HighScoreManager *highScoreManager,
                       long *score, string* playerInput) : AppState(window, renderer), highScoreManager(highScoreManager), score(score), font(), titleText(), entryText(), playerInput(playerInput), done(false) {
    font.loadFromFile("../res/Pixellari.ttf");
    titleText.setString("Enter name (" + to_string(MAX_NAME_SIZE) + " characters max) and press enter.");
    titleText.setFont(font);
    titleText.setPosition(100, 100);
    titleText.setCharacterSize(40);
    titleText.setFillColor(sf::Color::White);
    entryText.setString(">");
    entryText.setFont(font);
    entryText.setPosition(100, 200);
    entryText.setFillColor(sf::Color::Cyan);
    entryText.setCharacterSize(40);
}

void EnterScore::onEnable() {
    *playerInput = "";
    done = false;
}

void EnterScore::onDisable() {

}

void EnterScore::update(float delta, float camX, float camY) {
    if (!done) {
        entryText.setString(*playerInput);
        if (playerInput->size() == MAX_NAME_SIZE || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            ScoreRecord scoreRecord;
            scoreRecord.setScore(*score);
            scoreRecord.setName(*playerInput);
            highScoreManager->addScore(scoreRecord);
            done = true;
            cout << "DONE" << endl;
        }
    }


}

void EnterScore::render(float delta, float camX, float camY) {
    window->draw(titleText);
    window->draw(entryText);
}

bool EnterScore::isDone() const {
    return done;
}
