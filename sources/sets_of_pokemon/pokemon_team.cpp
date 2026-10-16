#include "../../includes/sets_of_pokemon/pokemon_team.hpp"

#include <algorithm>
#include <iostream>

void pokemon_team::add_pokemon(const pokemon& pokemon) {
    if (array_of_pokemons.size() >= 6) {
        // Limite de pokemon*
        // replace focntion de remplacement
        return;
    }
    else {
        array_of_pokemons.push_back(pokemon);
    }
}

void pokemon_team::remove_pokemon(const pokemon& pokemon_to_remove) {
    auto it = std::remove(array_of_pokemons.begin(), array_of_pokemons.end(), pokemon_to_remove);
    if (it != array_of_pokemons.end()) {
        array_of_pokemons.erase(it, array_of_pokemons.end());
    }
}

void pokemon_team::heal_all_pokemons() {
    for (pokemon& p : array_of_pokemons) {
        p.full_heal();
    }
}