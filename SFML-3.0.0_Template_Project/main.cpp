#include <SFML/Graphics.hpp>
#include "Enemy.h"

int main()
{
    //Declare window dimension as constants to avoid magic numbers
    constexpr int WIN_WIDTH = 800;
    constexpr int WIN_HEIGHT = 600;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ WIN_WIDTH, WIN_HEIGHT}), "SFML Program");

    std::vector<Enemy*> enemies;
    std::vector<sf::Vector2f> patrol0 = { sf::Vector2f(100,100), sf::Vector2f(600, 100), sf::Vector2f(600, 300) };
    std::vector<sf::Vector2f> patrol1 = { sf::Vector2f(100,500), sf::Vector2f(300, 500) };

    enemies.push_back(new Enemy(patrol0, 100.0f, 50.0f, 3.f));
    enemies.push_back(new Enemy(patrol1, 150.0f, 50.0f, 1.f));

    sf::Vector2f playerPos = sf::Vector2f(400, 300);

    sf::Clock clock;
    // Start the game loop
    // And keep it running until the window is closed
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        //Process events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        playerPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        // update enemies
        for (auto e : enemies)
            e->update(dt, playerPos);

        window.clear();     //Clear screen
        // draw enemies
        for (auto e : enemies)
            e->draw(window);
        window.display();   //Update screen
    }

    return EXIT_SUCCESS;
}