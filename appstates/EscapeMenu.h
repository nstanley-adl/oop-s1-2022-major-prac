//
// Created by nstan on 24/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_ESCAPEMENU_H
#define OOP_S1_2022_MAJOR_PRAC_ESCAPEMENU_H


#include "AppState.h"

enum MenuOption {
    CONTINUE = 0,
    VIEW_HIGH_SCORES = 1,
    EXIT_GAME = 2,
};

class EscapeMenu: public AppState {
protected:
    sf::Font font;
    sf::Clock selectionChangeCoolDown;
    vector<string> options;
    vector<sf::Text*> optionText;
    MenuOption menuResult;
    int selectedOption;
public:
    EscapeMenu(sf::RenderWindow *window, EntityRenderer *renderer);

    void onEnable() override;

    void onDisable() override;

    void update(float delta, float camX, float camY) override;

    void render(float delta, float camX, float camY) override;

    MenuOption getMenuResult() const;
};


#endif //OOP_S1_2022_MAJOR_PRAC_ESCAPEMENU_H
