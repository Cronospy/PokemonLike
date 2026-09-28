#pragma once

#include "sets_of_pokemon/pokemon_box.hpp"
#include "sets_of_pokemon/pokemon_team.hpp"

class player {
    private:
        pokemon_team team;
        pokemon_box box;
    public:
        player();
        pokemon_team& get_team();
        pokemon_box& get_box();
};