#include "Game.h"

int main()
{
    Game game;

    while (!game.GetWindow()->IsDone()) {

        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && game.GetGameOver()) {
            game.ResetGame();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !game.GetIsGameRunning()) {
            game.StartGame();
        }
    }
    return 0;
}
