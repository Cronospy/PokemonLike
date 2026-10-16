#include "../../includes/sets_of_pokemon/set_of_pokemon.hpp"

#include <stdexcept>

set_of_pokemon::set_of_pokemon() = default;

void set_of_pokemon::display_all_pokemon() {
    for (const pokemon& pokemon: array_of_pokemons) {
        pokemon.display_all();
    }
}

pokemon set_of_pokemon::get_by_id(int id) {
    for (const pokemon& pokemon: array_of_pokemons) {
        if (pokemon.get_id() == id) {
            return pokemon;
        }
    }
    throw std::invalid_argument("Pokemon id not found");
}

pokemon set_of_pokemon::get_by_name(const std::string& name) {
    for (const pokemon& pokemon: array_of_pokemons) {
        if (pokemon.get_name() == name) {
            return pokemon;
        }
    }
    throw std::invalid_argument("Pokemon id not found");
}
