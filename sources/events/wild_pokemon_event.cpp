#include <iostream>
using namespace std;
#include <random>

#include "../../includes/events/wild_pokemon_event.hpp"
#include "../../includes/widgets/team_display.hpp"
#include "../../includes/sets_of_pokemon/pokedex.hpp"

bool attempt_capture(const pokemon &wild_pokemon);

wild_pokemon_event::wild_pokemon_event(player* player) : current_player(player) {
    if (!background_texture.loadFromFile("assets/images/wild_pokemon_bg.png"))
        std::cout << "Error: Could not display background image" << std::endl;
    if (!title_font.openFromFile("assets/fonts/fiftiesMovies.ttf"))
        std::cout << "Can't find the font file" << std::endl;

    // Pokemon to capture
    auto wild_pokemon = pokedex::get_instance()->get_random_pokemon();
    if (!wild_pokemon_texture.loadFromFile("assets/images/pokemon/" + std::to_string(wild_pokemon.get_id()) + ".png"))
        std::cout << "Error: Could not display background image" << std::endl;

    // Button
    capture_button = make_unique<button>(title_font, "Capture !", sf::Vector2f{300.f, 75.f},sf::Vector2f{935.f, 640.f});
    capture_button->set_on_click([this,wild_pokemon]() -> void {
        if (attempt_capture(wild_pokemon)) {
            current_player->get_team().add_pokemon(wild_pokemon);
            team_widget->set_team(current_player->get_team());
        }
        finish();
    });
    // button skip ?
}

void wild_pokemon_event::update(const sf::RenderWindow& window) {
    if (!team_widget) {
        team_widget = std::make_unique<team_display>(
            current_player->get_team(), sf::Vector2f{112.f, 20.f});
    }
    capture_button->update(window);
}

void wild_pokemon_event::render(sf::RenderWindow& window) {
    set_background(window);
    if (team_widget) team_widget->render(window);
    set_wild_pokemon(window);
    capture_button->render(window);
}


void wild_pokemon_event::set_background(sf::RenderWindow& window) {
    Sprite backgroundImage(background_texture);

    backgroundImage.setTexture(background_texture, true);
    window.draw(backgroundImage);
}

void wild_pokemon_event::set_wild_pokemon(sf::RenderWindow& window) {
    Sprite wild_pokemon_sprite(wild_pokemon_texture);
    wild_pokemon_sprite.setPosition({835,385});
    wild_pokemon_sprite.setScale({2.0f,2.0f});
    window.draw(wild_pokemon_sprite);
}

bool attempt_capture(const pokemon& wild_pokemon) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    // Exemple : taux de base 60%, réduit si le Pokémon a beaucoup de PV
    int chance = 60 - (wild_pokemon.get_hit_points() / 10);
    if (chance < 15) chance = 15; // Garantie d'au moins 15% de chance

    return dist(gen) <= chance;
}