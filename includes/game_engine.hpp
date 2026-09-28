#pragma once
#include <vector>

#include "player.hpp"
#include "pokemon.hpp"
#include "game_states/game_states.hpp"
#include "sets_of_pokemon/pokemon_team.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class game_engine {
    private:
        game_states* game_state;
        player current_player;
        sf::RenderWindow* window;

    public:
        game_engine(game_states *game_state, sf::RenderWindow *window);

        void update();
        void render();

        void set_game_state(game_states* state);

        sf::RenderWindow* get_window();
        void start_game();
        void choose_starter_pokemon();

        std::vector<pokemon> select_starter_pokemon();

        player* get_player();
};
