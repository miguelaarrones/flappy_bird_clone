//
// Created by miguelaarrones on 17/09/2024.
//

#ifndef PIPE_H
#define PIPE_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"


class Pipe {
public:
    Pipe(sf::Texture &texture, bool isTopPipe);
    ~Pipe();

    void SetPosition(sf::Vector2f position);

    void Move(float elapsedTime);

    sf::Vector2f GetPosition();

    float GetWidth();

    sf::FloatRect GetGlobalBounds() const;

    void Draw(sf::RenderWindow & render_window);

    bool GetScored();

    void SetScored(bool hasScored);

private:
    sf::Sprite pipe;

    sf::Vector2f position;

    float speed = -200.0f; // Pipes move to the left (negative x-direction)
    float width = 80.0f;

    sf::Color color;

    bool scored;
};



#endif //PIPE_H
