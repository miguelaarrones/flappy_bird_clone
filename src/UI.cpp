//
// Created by miguelaarrones on 17/09/2024.
//

#include "UI.h"

#include "Window.h"

void UI::Setup(Window &window) {
    uiBackground.setSize(sf::Vector2f(800, 600));
    uiBackground.setFillColor(sf::Color(189, 176, 175, 100));
    uiBackground.setPosition(0, 0);

    font.loadFromFile("resources/fonts/flappy-font.ttf");

    gameOverText = sf::Text("GAME OVER", font);
    gameOverText.setCharacterSize(40);
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2, gameOverText.getLocalBounds().height / 2 );
    gameOverText.setPosition(window.GetWindowSize().x / 2, window.GetWindowSize().y / 2);

    pressToRestartText = sf::Text("PRESS ENTER TO RESTART", font);
    pressToRestartText.setCharacterSize(40);
    pressToRestartText.setOrigin(pressToRestartText.getLocalBounds().width / 2, pressToRestartText.getLocalBounds().height / 2 );
    pressToRestartText.setPosition(window.GetWindowSize().x / 2, (window.GetWindowSize().y / 2) + gameOverText.getLocalBounds().height + 10.0f);

    startText = sf::Text("FLAPPO BIRDO", font);
    startText.setCharacterSize(40);
    startText.setOrigin(startText.getLocalBounds().width / 2, startText.getLocalBounds().height / 2 );
    startText.setPosition(window.GetWindowSize().x / 2, window.GetWindowSize().y / 2);

    pressToStartText = sf::Text("PRESS ENTER TO START", font);
    pressToStartText.setCharacterSize(40);
    pressToStartText.setOrigin(pressToStartText.getLocalBounds().width / 2, pressToStartText.getLocalBounds().height / 2 );
    pressToStartText.setPosition(window.GetWindowSize().x / 2, (window.GetWindowSize().y / 2) + startText.getLocalBounds().height + 10.0f);

    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setPosition(10, 10);
}

void UI::UpdateScore(int score) {
    scoreText.setString("Score: " + std::to_string(score));
}

void UI::Draw(Window &window, bool isGameOver, bool isGameRunning) {
    window.Draw(scoreText);

    if (isGameOver) {
        window.Draw(uiBackground);
        window.Draw(gameOverText);
        window.Draw(pressToRestartText);
    } else if (!isGameRunning) {
        window.Draw(uiBackground);
        window.Draw(startText);
        window.Draw(pressToStartText);
    }
}
