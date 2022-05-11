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
public:
    Entity(sf::RenderWindow* window);
    virtual void update(float delta) = 0;
    virtual void render(float delta) = 0;
    ~Entity();
};


#endif //ENTITY_H
