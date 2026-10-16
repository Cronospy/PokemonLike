#include "../includes/game_engine.hpp"

#include "../includes/sets_of_pokemon/pokedex.hpp"
#include "../includes/player.hpp"
#include "../includes/game_states/game_states.hpp"
#include <SFML/Graphics.hpp>

class game_states;

game_engine::game_engine(std::unique_ptr<game_states> initial_state, sf::RenderWindow* window) {
    this->current_state = std::move(initial_state);
    current_state->set_engine(this);
    this->window = window;
    this->current_player = player();
}

void game_engine::update() {
    current_state->update();

    if (pending_state) {
        current_state = std::move(pending_state);
        current_state->set_engine(this);
    }
}

void game_engine::render() {
    current_state->render();
}

sf::RenderWindow* game_engine::get_window() {
    return this->window;
}

void game_engine::set_game_state(std::unique_ptr<game_states> new_state) {
    pending_state = std::move(new_state);
}

player* game_engine::get_player() {
    return &current_player;
}