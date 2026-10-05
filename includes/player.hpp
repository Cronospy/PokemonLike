#pragma once

#include <memory>

#include "sets_of_pokemon/pokemon_box.hpp"
#include "sets_of_pokemon/pokemon_team.hpp"

class player {
    private:
    std::unique_ptr<pokemon_team> team;
    std::unique_ptr<pokemon_box> box;
    public:
        player();
        pokemon_team& get_team();
        pokemon_box& get_box();
};