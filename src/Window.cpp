//
// Created by miguelaarrones on 16/09/2024.
//

#include "Window.h"

Window::Window() {
    Setup("Window", sf::Vector2u(800, 400));
}

Window::Window(const std::string &l_title, const sf::Vector2u &l_size) {
    Setup(l_title, l_size);
}

Window::~Window() {
    Destroy();
}

void Window::Setup(const std::string &l_title, const sf::Vector2u &l_size) {
    windowTitle = l_title;
    windowSize = l_size;
    isDone = false;
    Create();
}

void Window::Create() {
    window.create({ windowSize.x, windowSize.y}, windowTitle);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
}

void Window::Destroy() {
    window.close();
}

void Window::Update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isDone = true;
        }

    }
}

void Window::BeginDraw() {
    window.clear(sf::Color::Black);
}

void Window::EndDraw() {
    window.display();
}

bool Window::IsDone() {
    return isDone;
}

sf::Vector2u Window::GetWindowSize() {
    return windowSize;
}

void Window::Draw(sf::Drawable &l_drawable) {
    window.draw(l_drawable);
}

sf::RenderWindow & Window::GetRenderWindow() {
    return window;
}
