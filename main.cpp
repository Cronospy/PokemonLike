#include <iostream>
#include <SFML/Graphics.hpp>

#include "includes/game_engine.hpp"
#include "includes/game_states/menu_state.hpp"

using namespace sf;

int main()
{
    // SFML Config
    RenderWindow window( sf::VideoMode( { 1200, 800 } ), "Pokemon Like - IS" );
    window.setVerticalSyncEnabled(true);

    // Game Config
    auto* engine = new game_engine(std::make_unique<menu_state>(), &window);

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        engine->update();
        window.clear();
        engine->render();
        window.display();
    }
    return 0;
}