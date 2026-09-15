#pragma once
#include <vector>

#include "pokemon.hpp"
#include "pokemon_team.hpp"

class game_engine {
    private:
        pokemon_team pokemon_team;

    public:
        game_engine() = default;
        void start_game();
        void choose_starter_pokemon();
        std::vector<pokemon*> select_starter_pokemon();
};
