//
// Created by miguelaarrones on 16/09/2024.
//

#include "Bird.h"

#include <iostream>

Bird::Bird() {
    position = sf::Vector2f(50, 100);

    birdTexture01.loadFromFile("resources/bird-01.png");
    birdTexture02.loadFromFile("resources/bird-02.png");
    birdTexture03.loadFromFile("resources/bird-03.png");

    birdTextures.push_back(birdTexture01);
    birdTextures.push_back(birdTexture02);
    birdTextures.push_back(birdTexture03);

    birdSprite.setTexture(birdTexture01);

    birdSprite.setPosition(position);

    currentTexture = 0;

    wingSoundBuffer.loadFromFile("resources/audio/wing.wav");
    wingSound.setBuffer(wingSoundBuffer);

    dieSoundBuffer.loadFromFile("resources/audio/die.wav");
    dieSound.setBuffer(dieSoundBuffer);
}

Bird::~Bird() { }

void Bird::Draw(sf::RenderWindow &window) {
    window.draw(birdSprite);
}

void Bird::Update() {
    velocity += gravity;
    position.y += velocity;
    birdSprite.setPosition(position.x, position.y);

    if (flapClock.getElapsedTime() >= flapTimer) {
        currentTexture++;

        if (currentTexture >= birdTextures.size()) {
            currentTexture = 0;
        }

        birdSprite.setTexture(birdTextures[currentTexture]);

        flapClock.restart();
    }
}

void Bird::Flap() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) {
        velocity = jumpStrength;
        canJump = false;
        wingSound.play();
    }

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        canJump = true;
    }
}

bool Bird::CheckBirdBounds(float windowHeight) {
    if (birdSprite.getPosition().y + birdSprite.getLocalBounds().getSize().y > windowHeight)
    {
        birdSprite.setPosition(birdSprite.getPosition().x, windowHeight - birdSprite.getLocalBounds().getSize().y);
        velocity = 0;

        dieSound.play();
        return true;
    }

    if (birdSprite.getPosition().y < 0)
    {
        birdSprite.setPosition(birdSprite.getPosition().x, 0);
        velocity = 0;
    }

    return false;
}

sf::FloatRect Bird::GetLocalBounds() {
    return birdSprite.getLocalBounds();
}

sf::FloatRect Bird::GetGlobalBounds() {
    return birdSprite.getGlobalBounds();
}

sf::Vector2f Bird::GetPosition() {
    return position;
}

void Bird::SetPosition(float x, float y) {
    this->position = sf::Vector2f(x, y);
}

void Bird::SetVelocity(float velocity) {
    this->velocity = velocity;
}

void Bird::Reset() {
    position = sf::Vector2f(50, 100);
    velocity = 0;
}

void Bird::PlayDeathSound() {
    dieSound.play();
}


