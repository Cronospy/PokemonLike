#include <iostream>

#include "includes/game_engine.hpp"
#include "includes/pokedex.hpp"

int main() {
    auto _ = pokedex::get_instance();
    game_engine engine;
    engine.start_game();
    return 0;
}

/*#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Hello SFML 3");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {

        // Nouveau système d'événements SFML 3
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }

    return 0;
}*/
