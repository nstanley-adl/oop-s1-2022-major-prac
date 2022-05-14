//
// Created by nstan on 7/05/2022.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class Entity {
protected:
    sf::RenderWindow* window;
    sf::Vector2<float>* position;
public:
    Entity(sf::RenderWindow* window);
    virtual void update(float delta) = 0;
    virtual void render(float delta) = 0;
    void setPosition(float x, float y);
    float getXPosition();
    float getYPosition();
    ~Entity();
};


#endif //ENTITY_H
