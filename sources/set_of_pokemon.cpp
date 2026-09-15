#include "../includes/set_of_pokemon.hpp"

set_of_pokemon::set_of_pokemon() {
    array_of_pokemons = {};
};

void set_of_pokemon::display_all_pokemon() {
    for (pokemon* pokemon: array_of_pokemons) {
        pokemon->display_all();
    }
}

pokemon* set_of_pokemon::get_by_id(int id) {
    for (pokemon* pokemon: array_of_pokemons) {
        if (pokemon->get_id() == id) {
            return pokemon;
        }
    }
    return nullptr;
}

pokemon* set_of_pokemon::get_by_name(std::string name) {
    for (pokemon* pokemon: array_of_pokemons) {
        if (pokemon->get_name() == name) {
            return pokemon;
        }
    }
    return nullptr;
}
