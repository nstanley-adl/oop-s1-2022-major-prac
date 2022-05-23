//
// Created by nstan on 21/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_BULLETSTREAM_H
#define OOP_S1_2022_MAJOR_PRAC_BULLETSTREAM_H


const float MAX_SEARCHES = 1;
const float SEARCH_DISTANCE = 60;
const float HIT_MAGNITUDE = 60;

#include "Entity.h"

using namespace std;

class BulletStream: public Entity {
protected:
    sf::Vertex line[2];
    vector<sf::CircleShape*> circles;
    bool hidden;
public:
    BulletStream(sf::RenderWindow *window, const sf::Color &bulletColor);

    void update(float delta) override;

    void render(float delta, float camX, float camY) override;

    void setEndPoint(const sf::Vector2i &endPoint);

    bool checkCollision(const sf::Vector2f &targetPoint, bool drawDebugCircles);

    bool isHidden() const;

    void setHidden(bool hidden);

    virtual ~BulletStream();
};


#endif //OOP_S1_2022_MAJOR_PRAC_BULLETSTREAM_H
