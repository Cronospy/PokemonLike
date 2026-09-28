#pragma once
#include "../pokemon.hpp"
#include "set_of_pokemon.hpp"

/*
 * Cette classe permet de manipuler l'équipe du joueur
 * Il y a une limite de 6 pokémon
 */

class pokemon_team : public set_of_pokemon {
    public:
        pokemon_team() = default;
        void add_pokemon(const pokemon& pokemon);
        void remove_pokemon(const pokemon& pokmeon_to_remove);
        void display_pokemon_team();
};
