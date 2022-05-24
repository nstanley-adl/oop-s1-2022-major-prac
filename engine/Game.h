//
// Created by nstan on 9/05/2022.
//

#ifndef GAME_H
#define GAME_H

#include "BaseApplication.h"
#include "../entities/PlayerEntity.h"
#include "../appstates/GamePlayAppState.h"
#include "../appstates/TitleScreenAppState.h"
#include "../appstates/EndScreenAppState.h"
#include "../appstates/EscapeMenu.h"
#include "../util/HighScoreManager.h"
#include "../appstates/ScoreBoard.h"
#include "../appstates/EnterScore.h"

enum GameState {
    TITLE_SCREEN = 0,
    PLAYING = 1,
    SCORE_BOARD = 2,
    END_SCREEN = 3,
    TYPING_SCORE = 4,
};


class Game: public BaseApplication {
protected:
    TitleScreenAppState titleScreenAppState;
    GamePlayAppState gamePlayAppState;
    EndScreenAppState endScreenAppState;
    EscapeMenu escapeMenu;
    GameState lastState;
    HighScoreManager highScoreManager;
    ScoreBoard scoreBoard;
    EnterScore enterScore;
    long score;
    void initialise() override;
    void update(float delta, float camX, float camY) override;
    void render(float delta, float camX, float camY) override;
public:
    Game();
};



#endif //GAME_H
