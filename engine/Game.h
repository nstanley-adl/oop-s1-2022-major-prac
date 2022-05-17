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

class Game: public BaseApplication {
protected:
    TitleScreenAppState titleScreenAppState;
    GamePlayAppState gamePlayAppState;
    EndScreenAppState endScreenAppState;
    void initialise() override;
    void update(float delta) override;
    void render(float delta) override;
public:
    Game();
};


#endif //GAME_H
