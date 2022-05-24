//
// Created by nstan on 21/05/2022.
//

#include <cmath>
#include <iostream>
#include "BulletStream.h"
#include "../engine/GameConstants.h"

using namespace std;

BulletStream::BulletStream(sf::RenderWindow *window, const sf::Color &bulletColor)
        : Entity(window), hidden(true), circles() {
    line[0] = sf::Vertex(sf::Vector2f(WINDOW_WIDTH/2,WINDOW_HEIGHT/2));
    line[1] = sf::Vertex();
    for (auto vertex : line) {
        vertex.color = bulletColor;
    }
}

void BulletStream::update(float delta) {

}

void BulletStream::render(float delta, float camX, float camY) {
    if (!hidden) {
        window->draw(line, 2, sf::Lines);
        for (sf::CircleShape* circle : circles) {
            window->draw(*circle);
        }
    }


}

void BulletStream::setEndPoint(const sf::Vector2i &endPoint) {
    sf::Vector2f calculatedEndpoint;
    float lineLength = sqrt(pow((WINDOW_WIDTH/2) - endPoint.x, 2.0) + pow((WINDOW_HEIGHT/2) - endPoint.y, 2.0));
    calculatedEndpoint.x = (float) endPoint.x + ((float) endPoint.x - (WINDOW_WIDTH/2)) / 1 * lineLength;
    calculatedEndpoint.y = (float) endPoint.y + ((float) endPoint.y - (WINDOW_HEIGHT/2)) / 1 * lineLength;
    line[1].position = sf::Vector2f(calculatedEndpoint.x, calculatedEndpoint.y);
}

void BulletStream::setHidden(bool hidden) {
    BulletStream::hidden = hidden;
//    if (hidden) for (sf::CircleShape* circle : circles) delete circle;
//    circles.clear();
}

bool BulletStream::checkCollision(const sf::Vector2f &targetPoint, bool drawDebugCircles) {
    sf::Vector2f startPoint = line[0].position;
    sf::Vector2f endPoint = line[1].position;
    sf::Vector2f searchPoint;
    float dist = sqrt(pow(endPoint.x - startPoint.y, 2.0) + pow(endPoint.y - startPoint.x, 2.0));
    float t, targetDist;
    for (sf::CircleShape* circle : circles) delete circle;
    circles.clear();

    if (drawDebugCircles) {
        sf::CircleShape* circleShape = new sf::CircleShape(HIT_MAGNITUDE/2);
        circleShape->setPosition(targetPoint.x - (HIT_MAGNITUDE/2), targetPoint.y - (HIT_MAGNITUDE/2));
        circleShape->setFillColor(sf::Color(0,255,0,230));
        circles.push_back(circleShape);
    }
//    cout << "-------------" << endl;
    int count = 0;
    do {
        t = SEARCH_OFFSET / dist;
        searchPoint.x = ((1.f - t) * startPoint.x + t * endPoint.x);
        searchPoint.y = ((1.f - t) * startPoint.y + t * endPoint.y);
        targetDist = sqrt(pow(searchPoint.x - targetPoint.x, 2.0) + pow(targetPoint.y - searchPoint.y, 2.0));
        if (targetDist <= HIT_MAGNITUDE) {return true;}
//        cout << targetDist << " ";
//        printf("(%f,%f) - (%f,%f)\n", searchPoint.x, searchPoint.y, targetPoint.x, targetPoint.y);
//        cout << endl;
        startPoint = searchPoint;
        if (drawDebugCircles) {
            sf::CircleShape* circleShape = new sf::CircleShape(20);
            circleShape->setPosition(searchPoint.x - 10, searchPoint.y - 10);
            circleShape->setFillColor(sf::Color(255, 0,0,230));
            circles.push_back(circleShape);
        }
        count++;
    } while ((t > 0 && t < 1) && count < MAX_SEARCHES);
    return false;
}

BulletStream::~BulletStream() {
    for (sf::CircleShape* circle : circles) delete circle;
}

bool BulletStream::isHidden() const {
    return hidden;
}

