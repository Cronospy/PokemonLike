#include "set_of_pokemon.hpp"

class Pokedex : public SetOfPokemon{
    private:
        Pokedex* instance;
        Pokedex(string fileName);
    public:
        Pokedex* getInstance();
};
