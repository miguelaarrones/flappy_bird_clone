//
// Created by miguelaarrones on 17/09/2024.
//

#include "Pipe.h"

#include <iostream>
#include <ostream>

#include "SFML/Graphics/Texture.hpp"

Pipe::Pipe(sf::Texture &texture, bool isTopPipe) {
    pipe.setTexture(texture);

    if (isTopPipe) {
        pipe.setOrigin(pipe.getLocalBounds().width, 0);
        pipe.rotate(180);
    }
}

Pipe::~Pipe() { }

void Pipe::SetPosition(sf::Vector2f position) {
    this->position = position;
}

void Pipe::Move(float elapsedTime) {
    position.x += speed * elapsedTime;
    pipe.setPosition(position.x, position.y);
}

sf::Vector2f Pipe::GetPosition() {
    return position;
}

float Pipe::GetWidth() {
    return width;
}

sf::FloatRect Pipe::GetGlobalBounds() const {
    return pipe.getGlobalBounds();
}

void Pipe::Draw(sf::RenderWindow &render_window) {
    render_window.draw(pipe);
}

bool Pipe::GetScored() {
    return scored;
}

void Pipe::SetScored(bool hasScored) {
    scored = hasScored;
}
