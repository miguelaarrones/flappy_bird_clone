//
// Created by miguelaarrones on 16/09/2024.
//

#include "Game.h"

#include <iostream>

Game::Game() : window("Flappo Birdo", sf::Vector2u(800, 512)), bird() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    backgroundTexture.loadFromFile("resources/background.png");
    backgroundSprite.setTexture(backgroundTexture);

    ui.Setup(window);

    pipeTexture.loadFromFile("resources/pipe.png");

    startSoundBuffer.loadFromFile("resources/audio/swoosh.wav");
    startSound.setBuffer(startSoundBuffer);

    scoreSoundBuffer.loadFromFile("resources/audio/point.wav");
    scoreSound.setBuffer(scoreSoundBuffer);
}

Game::~Game() {

}

void Game::Update() {
    window.Update();

    ui.UpdateScore(score);

    if (!isGameOver && isGameRunning) {
        float deltaTime = GetElapsed().asSeconds();

        bird.Update();
        isGameOver = bird.CheckBirdBounds(window.GetWindowSize().y);

        SpawnPipe();
        MovePipes(deltaTime);
        // Score();
        CleanPipes();
        CheckBirdPassedPipe();

        if (CheckCollisions(bird, pipes)) {
            bird.PlayDeathSound();
            ToggleGameOver();
        }
    }
}

void Game::DrawPipes(sf::RenderWindow &render_window) {
    for (auto pipe: pipes) {
        pipe.Draw(render_window);
    }
}

void Game::DrawBackground() {
    float repeat = 800 / backgroundSprite.getLocalBounds().width;
    backgroundSprite.setPosition(0, 0);
    for (int i = 0; i < repeat; ++i) {
        window.Draw(backgroundSprite);
        backgroundSprite.setPosition(backgroundSprite.getPosition().x + backgroundSprite.getLocalBounds().width, 0);
    }
}

void Game::Render() {
    window.BeginDraw();

    DrawBackground();

    bird.Draw(window.GetRenderWindow());
    DrawPipes(window.GetRenderWindow());

    ui.Draw(window, isGameOver, isGameRunning);

    window.EndDraw();
}

Window *Game::GetWindow() {
    return &window;
}

void Game::HandleInput() {
    if (!isGameOver && isGameRunning) {
        bird.Flap();
    }
}

void Game::ResetGame() {
    ToggleGameOver();
    pipes.clear();
    bird.Reset();
    score = 0;
}

void Game::SpawnPipe() {
    if (pipeSpawnClock.getElapsedTime() >= pipeSpawnInterval) {
        float topPipePos = static_cast<float>(std::rand() % 300 + 50);

        Pipe topPipe = Pipe(pipeTexture, true);
        topPipe.SetPosition(sf::Vector2f(window.GetWindowSize().x, topPipePos));

        float bottomPipeY = topPipePos + pipeGapHeight;
        Pipe bottomPipe = Pipe(pipeTexture, false);
        bottomPipe.SetPosition(sf::Vector2f(window.GetWindowSize().x, bottomPipeY));

        topPipe.SetScored(false);
        bottomPipe.SetScored(true);

        pipes.push_back(topPipe);
        pipes.push_back(bottomPipe);

        pipeSpawnClock.restart();
    }
}

void Game::MovePipes(float elapsedTime) {
    for (auto& pipe : pipes)
    {
        pipe.Move(elapsedTime);
    }
}

void Game::CleanPipes() {
    for (size_t i = 0; i < pipes.size(); i++)
    {
        if (pipes[i].GetPosition().x + pipes[i].GetWidth() < 0) {
            pipes.erase(pipes.begin() + i);
            // passedPipes.erase(passedPipes.begin() + i);
        }
    }
}

bool Game::CheckCollisions(Bird &bird, const std::vector<Pipe> &pipes) {
    for (const auto& pipe : pipes)
    {
        if (bird.GetGlobalBounds().intersects(pipe.GetGlobalBounds()))
        {
            return true;
        }
    }
    return false;
}

void Game::CheckBirdPassedPipe() {
    if (pipes.empty()) return;
    if (bird.GetPosition().x > pipes[0].GetPosition().x + pipes[0].GetWidth()) {
        if (!pipes[0].GetScored()) {
            pipes[0].SetScored(true);
            score++;
            scoreSound.play();
        }
    }
}

// Scoring once every second.
void Game::Score() {
    if (scoreClock.getElapsedTime() >= scoreInterval) {
        score++;
        scoreClock.restart();
    }
}

sf::Time Game::GetElapsed() {
    return elapsed;
}

void Game::RestartClock() {
    elapsed = clock.restart();
}

bool Game::GetGameOver() {
    return isGameOver;
}

void Game::ToggleGameOver() {
    isGameOver = !isGameOver;
}

bool Game::GetIsGameRunning() {
    return isGameRunning;
}

void Game::StartGame() {
    isGameRunning = true;
    startSound.play();
}






