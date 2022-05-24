//
// Created by nstan on 9/05/2022.
//

#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(): BaseApplication(), score(), gamePlayAppState(window, renderer, &score), titleScreenAppState(window, renderer),
              endScreenAppState(window, renderer, &score), escapeMenu(window, renderer), highScoreManager(), scoreBoard(window, renderer, &highScoreManager),
              enterScore(window, renderer, &highScoreManager, &score, &playerInput) {
    this->trackAppState(&gamePlayAppState);
    this->trackAppState(&titleScreenAppState);
    this->trackAppState(&endScreenAppState);
    this->trackAppState(&escapeMenu);
    this->trackAppState(&scoreBoard);
    this->trackAppState(&enterScore);
    titleScreenAppState.enable();
    lastState = TITLE_SCREEN;
}

void Game::initialise() {
    cout << "game initialising :)" << endl;
//    system("start https://youtu.be/J2X5mJ3HDYE");
}

void Game::update(float delta, float camX, float camY) {
    if (gamePlayAppState.isEnabled() && gamePlayAppState.isGameOver()) {
        gamePlayAppState.disable();
        if (highScoreManager.scoreIsCompetitive(score)) {
            enterScore.enable();
        } else {
            endScreenAppState.enable();
        }
        lastState = END_SCREEN;
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (titleScreenAppState.isEnabled()) {
                titleScreenAppState.disable();
                gamePlayAppState.enable();
                gamePlayAppState.resetGame();
                lastState = PLAYING;
            } else if (endScreenAppState.isEnabled()) {
                endScreenAppState.disable();
                gamePlayAppState.enable();
                gamePlayAppState.resetGame();
                lastState = PLAYING;
            }
        }
    }

    if (enterScore.isEnabled() && enterScore.isDone()) {
        enterScore.disable();
        scoreBoard.enable();
    }

    if (scoreBoard.isEnabled() && enterPressed) {
        scoreBoard.disable();
        switch (lastState) {
            case TITLE_SCREEN:
                titleScreenAppState.enable();
                break;
            case PLAYING:
                gamePlayAppState.enable();
                break;
            case END_SCREEN:
                endScreenAppState.enable();
                break;
        }
    }



    // escape menu
    if (escapePressed && !escapeMenu.isEnabled() && !enterScore.isEnabled()) {
        gamePlayAppState.disable();
        endScreenAppState.disable();
        titleScreenAppState.disable();
        scoreBoard.disable();
        escapeMenu.enable();
    } else if ((enterPressed || escapePressed) && escapeMenu.isEnabled() && !enterScore.isEnabled()) {
        if (escapeMenu.getMenuResult() == EXIT_GAME) exit();
        else if (escapeMenu.getMenuResult() == VIEW_HIGH_SCORES) {
            scoreBoard.enable();
        } else { // continue/close menu
            switch (lastState) {
                case TITLE_SCREEN:
                    titleScreenAppState.enable();
                    break;
                case PLAYING:
                    gamePlayAppState.enable();
                    break;
                case END_SCREEN:
                    endScreenAppState.enable();
                    break;
            }
        }
        escapeMenu.disable();
    }


}

void Game::render(float delta, float camX, float camY) {

}
