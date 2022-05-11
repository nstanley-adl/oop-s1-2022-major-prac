//
// Created by nstan on 9/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_GAME_H
#define OOP_S1_2022_MAJOR_PRAC_GAME_H

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


#endif //OOP_S1_2022_MAJOR_PRAC_GAME_H
