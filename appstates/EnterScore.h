//
// Created by nstan on 24/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_ENTERSCORE_H
#define OOP_S1_2022_MAJOR_PRAC_ENTERSCORE_H


#include "AppState.h"
#include "../util/HighScoreManager.h"

const int MAX_NAME_SIZE = 5;

class EnterScore: public AppState {
protected:
    HighScoreManager* highScoreManager;
    long* score;
    string* playerInput;
    sf::Font font;
    sf::Text titleText;
    sf::Text entryText;
    bool done;

public:
    EnterScore(sf::RenderWindow *window, EntityRenderer *renderer, HighScoreManager *highScoreManager, long *score, string* playerInput);

    void onEnable() override;

    void onDisable() override;

    void update(float delta, float camX, float camY) override;

    void render(float delta, float camX, float camY) override;

    bool isDone() const;
};


#endif //OOP_S1_2022_MAJOR_PRAC_ENTERSCORE_H
