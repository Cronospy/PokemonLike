#include <vector>

#include "pokemon.hpp"

class SetOfPokemon {
    public:
        std::vector<Pokemon*> arrayOfPokemons;

        SetOfPokemon();

        void display_all_pokemon();

        virtual Pokemon get_by_name(std::string name) = 0;
        virtual Pokemon get_by_id(int id) = 0;
        virtual ~SetOfPokemon() = default;
};

