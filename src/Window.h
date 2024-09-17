//
// Created by miguelaarrones on 16/09/2024.
//

#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <SFML/Graphics.hpp>


class Window {
public:
    Window();
    Window(const std::string &l_title, const sf::Vector2u &l_size);
    ~Window();

    void BeginDraw();
    void EndDraw();

    void Update();

    bool IsDone();
    sf::Vector2u GetWindowSize();

    void Draw(sf::Drawable &l_drawable);

    sf::RenderWindow & GetRenderWindow();

private:
    void Setup(const std::string &l_title, const sf::Vector2u &l_size);
    void Destroy();
    void Create();

    sf::RenderWindow window;
    sf::Vector2u windowSize;
    std::string windowTitle;
    bool isDone;
};



#endif //WINDOW_H
