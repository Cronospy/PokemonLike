#include "../includes/pokemon_team.hpp"

#include <algorithm>
#include <iostream>

void pokemon_team::add_pokemon(pokemon* pokemon) {
    if (array_of_pokemons.size() >= 6) {
        // Limite de pokemon*
        // replace focntion de remplacement
        return;
    }
    else {
        array_of_pokemons.push_back(pokemon);
    }
}

void pokemon_team::remove_pokemon(pokemon* pokemon) {
    array_of_pokemons.erase(find(array_of_pokemons.begin(),array_of_pokemons.end(),pokemon));
}

void pokemon_team::display_pokemon_team() {
    for (int i = 0; i < array_of_pokemons.size(); i++) {
        std::cout << i+1 << ": " << array_of_pokemons.at(i)->get_name() << std::endl;
    }
}