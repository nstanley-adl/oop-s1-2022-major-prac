//
// Created by nstan on 17/05/2022.
//

#include "ScreenLabelEntity.h"


using namespace std;

ScreenLabelEntity::ScreenLabelEntity(sf::RenderWindow *window, string fileName) : Entity(window), titleScreenTexture(),
                                                                                  titleScreenSprite(), r(0), g(0), b(0), colourIncrement(3) {
    titleScreenTexture.loadFromFile(fileName);
    titleScreenSprite.setTexture(titleScreenTexture);

}

void ScreenLabelEntity::update(float delta) {
    if (!countDown) {
        if (r < 255) r+= colourIncrement;
        else if (g < 255) g+=colourIncrement;
        else if (b < 255) b+=colourIncrement;
    } else {
        if (r > 0) r-=colourIncrement;
        else if (g > 0) g-=colourIncrement;
        else if (b > 0) b-=colourIncrement;
    }
    if (r+g+b == 255*3) countDown = true;
    else if (r+g+b <= 50) countDown = false;
    titleScreenSprite.setColor(sf::Color((int)r,(int)g,(int)b));

}

void ScreenLabelEntity::render(float delta, float camX, float camY) {
    window->draw(titleScreenSprite);
}


