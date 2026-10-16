#include "../../includes/game_states/playing_state.hpp"

#include <iostream>

#include "../../includes/game_engine.hpp"
#include "../../includes/events/pokecenter_event.hpp"
#include "../../includes/events/wild_pokemon_event.hpp"
#include "../../includes/game_states/menu_state.hpp"
#include "../../includes/game_states/win_state.hpp"

playing_state::playing_state(game_engine* engine) {
    this->engine = engine;
    current_id = 0;
    events.push_back(std::make_unique<wild_pokemon_event>(engine->get_player()));
    events.push_back(std::make_unique<pokecenter_event>(engine->get_player()));
    events.push_back(std::make_unique<wild_pokemon_event>(engine->get_player()));
    events.push_back(std::make_unique<wild_pokemon_event>(engine->get_player()));
    events.push_back(std::make_unique<wild_pokemon_event>(engine->get_player()));
    events.push_back(std::make_unique<wild_pokemon_event>(engine->get_player()));
    events.push_back(std::make_unique<wild_pokemon_event>(engine->get_player()));
}

void playing_state::render() {
    events[current_id]->render(*engine->get_window());
}

void playing_state::update() {
    if (current_id >= static_cast<int>(events.size())) return;

    events[current_id]->update(*engine->get_window());

    if (events[current_id]->is_finished()) {
        ++current_id;
        if (current_id >= events.size()) {
            engine->set_game_state(std::make_unique<win_state>(engine));
        }
    }
}