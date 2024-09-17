//
// Created by miguelaarrones on 16/09/2024.
//

#ifndef GAME_H
#define GAME_H

#include "UI.h"
#include "Bird.h"
#include "Pipe.h"
#include "Window.h"


class Game {
public:
    Game();
    ~Game();

    void HandleInput();

    void ResetGame();

    void SpawnPipe();

    void MovePipes(float elapsedTime);

    void CleanPipes();

    bool CheckCollisions(Bird &bird, const std::vector<Pipe> &pipes);

    void CheckBirdPassedPipe();

    void Score();

    void Update();

    void DrawPipes(sf::RenderWindow & render_window);

    void DrawBackground();

    void Render();
    Window* GetWindow();

    sf::Time GetElapsed();
    void RestartClock();

    bool GetGameOver();

    void ToggleGameOver();

    bool GetIsGameRunning();

    void StartGame();

private:
    Window window;
    UI ui;

    sf::Clock clock;
    sf::Time elapsed;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    Bird bird;

    sf::Clock pipeSpawnClock;
    sf::Time pipeSpawnInterval = sf::seconds(2.0f);
    std::vector<Pipe> pipes;
    float pipeGapHeight = 200.0f;

    bool isGameOver = false;
    bool isGameRunning = false;

    int score = 0;
    sf::Clock scoreClock;
    sf::Time scoreInterval = sf::seconds(1.0f);

    sf::Texture pipeTexture;

    sf::SoundBuffer startSoundBuffer;
    sf::Sound startSound;

    sf::SoundBuffer scoreSoundBuffer;
    sf::Sound scoreSound;
};



#endif //GAME_H
