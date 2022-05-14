//
// Created by nstan on 9/05/2022.
//

#ifndef GAME_H
#define GAME_H

#include "BaseApplication.h"
#include "GreenCircleEntity.h"
#include "TestAppState.h"

class Game: public BaseApplication {
protected:
    TestAppState testAppState;
    void initialise() override;
    void update(float delta) override;
    void render(float delta) override;
public:
    Game();
};


#endif //GAME_H
