#include <iostream>
#include <ostream>

#include "includes/GameEngine.h"

/*int main() {
    std::cout << "*------------Pokemon 1-------------*" << std::endl;

    Pokemon pikachu(25, "Pikachu", 35, 55, 40, 1);
    pikachu.displayInfo();

    std::cout << "*------------Pokemon 2-------------*" << std::endl;

    Pokemon mustebouee(418, "Mustébouée",55, 65,35,4);
    mustebouee.displayInfo();

    std::cout << "*----------------------------------*" << std::endl;

    //Pokemon pikachuCopy(pikachu);
    //pikachuCopy.displayInfo();

    std::cout << "*----Mustébouée attack Pikachu----*" << std::endl;

    mustebouee.attack_on(pikachu);
    std::cout << "Pikachu Hit Point:" + std::to_string(pikachu.get_hit_points()) << std::endl;

    std::cout << "*----Mustébouée attack Pikachu----*" << std::endl;

    mustebouee.attack_on(pikachu);
    std::cout << "Pikachu Hit Point:" + std::to_string(pikachu.get_hit_points()) << std::endl;

    std::cout << "*----------------------------------*" << std::endl;

    return 0;
}
*/

int main() {
    GameEngine engine;
    engine.startGame();
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
