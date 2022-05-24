//
// Created by nstan on 24/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_BOSSMONSTER_H
#define OOP_S1_2022_MAJOR_PRAC_BOSSMONSTER_H


#include "Entity.h"
#include "Monster.h"

class BossMonster: public Monster {

public:
    explicit BossMonster(sf::RenderWindow *window);
};


#endif //OOP_S1_2022_MAJOR_PRAC_BOSSMONSTER_H
