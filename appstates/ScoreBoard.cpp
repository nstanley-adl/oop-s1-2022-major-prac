//
// Created by nstan on 24/05/2022.
//

#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(sf::RenderWindow *window, EntityRenderer *renderer, HighScoreManager *highScoreManager)
        : AppState(window, renderer), highScoreManager(highScoreManager), continueText(), blinkHidden(false), blinkClock(), closed(false) {
    font.loadFromFile("../res/Pixellari.ttf");
    continueText.setFont(font);
    continueText.setPosition(250, 600);
    continueText.setStyle(sf::Text::Bold);
    continueText.setFillColor(sf::Color::White);
    continueText.setCharacterSize(60);
    continueText.setString("continue <");
}

void ScoreBoard::onEnable() {
    float yPos = 50;
    int count = 0;
    for (auto text: scoreText) {
        delete text;
    }
    scoreText.clear();
    for (auto score : highScoreManager->getScores()) {
        if (count >= 5) break;
        auto* text = new sf::Text();
        text->setFont(font);
        text->setPosition(200, yPos);
        text->setFillColor(sf::Color::White);
        text->setCharacterSize(60);
        text->setString(score->getName() + " " + string(20-score->getName().length(), '.') +  " " + to_string(score->getScore()));
        yPos += 100;
        scoreText.push_back(text);
        count++;
    }
}

void ScoreBoard::onDisable() {

}

void ScoreBoard::update(float delta, float camX, float camY) {
    if (blinkClock.getElapsedTime().asSeconds() > 0.5) {
        if (blinkHidden) {
            continueText.setString("continue <");
            blinkHidden = false;
        } else {
            continueText.setString("continue");
            blinkHidden = true;
        }
        blinkClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        closed = true;
    }
}

void ScoreBoard::render(float delta, float camX, float camY) {
    for (auto text : scoreText) {
        window->draw(*text);
    }
    window->draw(continueText);
}

ScoreBoard::~ScoreBoard() {
    for (auto text: scoreText) {
        delete text;
    }
}

bool ScoreBoard::isClosed() const {
    return closed;
}
