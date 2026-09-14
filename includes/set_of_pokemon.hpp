#include <vector>

#include "pokemon.hpp"

class SetOfPokemon {
    public:
        std::vector<Pokemon*> arrayOfPokemons;

        SetOfPokemon();

        void display_all_pokemon();

        Pokemon* get_by_name(std::string name);
        Pokemon* get_by_id(int id);
        virtual ~SetOfPokemon() = default;
};

