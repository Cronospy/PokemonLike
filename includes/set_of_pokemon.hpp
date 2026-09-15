#pragma once
#include <vector>

#include "pokemon.hpp"

class set_of_pokemon {
    public:
        std::vector<pokemon*> array_of_pokemons;

        set_of_pokemon();

        void display_all_pokemon();

        pokemon* get_by_name(std::string name);
        pokemon* get_by_id(int id);
        virtual ~set_of_pokemon() = default;
};

