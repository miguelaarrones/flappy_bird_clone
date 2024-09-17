//
// Created by miguelaarrones on 17/09/2024.
//

#ifndef UI_H
#define UI_H
#include "Window.h"
#include "SFML/Graphics.hpp"


class UI {
public:
    void Setup(Window &window);

    void UpdateScore(int score);

    void Draw(Window &window, bool isGameOver, bool isGameRunning);

    void DrawStartMessage(Window & window);

private:
    sf::RectangleShape uiBackground;
    sf::Text gameOverText;
    sf::Text pressToRestartText;

    sf::Text startText;
    sf::Text pressToStartText;
    sf::Font font;

    sf::Text scoreText;
};



#endif //UI_H
