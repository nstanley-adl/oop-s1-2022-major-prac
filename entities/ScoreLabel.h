//
// Created by nstan on 24/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_SCORELABEL_H
#define OOP_S1_2022_MAJOR_PRAC_SCORELABEL_H


#include "Entity.h"

class ScoreLabel: public Entity {
protected:
    long* score;
    sf::Font font;
    sf::Text text;
public:
    ScoreLabel(sf::RenderWindow *window, long *score);

    void update(float delta) override;

    void render(float delta, float camX, float camY) override;

};


#endif //OOP_S1_2022_MAJOR_PRAC_SCORELABEL_H
