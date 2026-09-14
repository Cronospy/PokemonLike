#include "../includes/set_of_pokemon.hpp"

SetOfPokemon::SetOfPokemon() {
    arrayOfPokemons = {};
};

void SetOfPokemon::display_all_pokemon() {
    for (Pokemon* pokemon: arrayOfPokemons) {
        pokemon->displayAll();
    }
}

Pokemon* SetOfPokemon::get_by_id(int id) {
    for (Pokemon* pokemon: arrayOfPokemons) {
        if (pokemon->get_id() == id) {
            return pokemon;
        }
    }
    return nullptr;
}

Pokemon* SetOfPokemon::get_by_name(std::string name) {
    for (Pokemon* pokemon: arrayOfPokemons) {
        if (pokemon->get_name() == name) {
            return pokemon;
        }
    }
    return nullptr;
}
