#pragma once
#include "set_of_pokemon.hpp"

class pokedex : public set_of_pokemon{
    private:
        std::vector<pokemon> pokemons_list;
        static pokedex* instance;
        pokedex();
    public:
        static pokedex *get_instance();
};
