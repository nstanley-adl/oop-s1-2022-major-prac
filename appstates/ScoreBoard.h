//
// Created by nstan on 24/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_SCOREBOARD_H
#define OOP_S1_2022_MAJOR_PRAC_SCOREBOARD_H


#include "AppState.h"
#include "../util/HighScoreManager.h"

class ScoreBoard: public AppState {
protected:
    sf::Font font;
    vector<sf::Text*> scoreText;
    HighScoreManager* highScoreManager;
    sf::Text continueText;
    sf::Clock blinkClock;
    bool blinkHidden;
    bool closed;

public:
    ScoreBoard(sf::RenderWindow *window, EntityRenderer *renderer, HighScoreManager *highScoreManager);

    void onEnable() override;

    void onDisable() override;

    void update(float delta, float camX, float camY) override;

    void render(float delta, float camX, float camY) override;

    virtual ~ScoreBoard();

    bool isClosed() const;

};


#endif //OOP_S1_2022_MAJOR_PRAC_SCOREBOARD_H
