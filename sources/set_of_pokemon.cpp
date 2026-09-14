#include "../includes/set_of_pokemon.hpp"

SetOfPokemon::SetOfPokemon() {
    arrayOfPokemons = {};
};

void SetOfPokemon::display_all_pokemon() {
    for (Pokemon* pokemon: arrayOfPokemons) {
        pokemon->displayAll();
    }
}