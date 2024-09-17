//
// Created by miguelaarrones on 16/09/2024.
//

#ifndef BIRD_H
#define BIRD_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"


class Bird {
public:
    Bird();
    ~Bird();

    void Draw(sf::RenderWindow &window);
    void Update();
    void Flap();

    bool CheckBirdBounds(float windowHeight);

    sf::FloatRect GetLocalBounds();
    sf::FloatRect GetGlobalBounds();
    sf::Vector2f GetPosition();
    void SetPosition(float x, float y);
    void SetVelocity(float velocity);

    void Reset();

    void PlayDeathSound();

private:
    sf::Vector2f position;

    sf::Texture birdTexture01;
    sf::Texture birdTexture02;
    sf::Texture birdTexture03;
    sf::Sprite birdSprite;

    float gravity = 0.5f;
    float jumpStrength = -8.0f;
    float velocity = 0.0f;

    sf::Clock flapClock;
    sf::Time flapTimer = sf::seconds(.1f);
    std::vector<sf::Texture> birdTextures;
    int currentTexture;

    sf::SoundBuffer wingSoundBuffer;
    sf::Sound wingSound;

    sf::SoundBuffer dieSoundBuffer;
    sf::Sound dieSound;

    bool canJump = true;
};



#endif //BIRD_H
