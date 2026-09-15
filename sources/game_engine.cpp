#include <iostream>

#include "../includes/game_engine.hpp"

#include "../includes/pokedex.hpp"

void game_engine::start_game() {
    std::cout << "*------------ New Game ------------*" << std::endl;

    choose_starter_pokemon();

    std::cout << "*----------- Your Team: -----------*" << std::endl;
    pokemon_team.display_pokemon_team();
}

void game_engine::choose_starter_pokemon() {
    std::cout << "*------ Choose Your Starter! ------*" << std::endl;

    std::vector<pokemon*> pokemons = select_starter_pokemon();

    //Selection
    int index;
    do {
        std::cout << "*--------- Select 1,2 or 3 ---------*" << std::endl;
        std::cin >> index;
        index-=1;
    }while (index < 0 || index > pokemons.size()-1);

    //Ajout à l'equipe
    pokemon_team.add_pokemon(pokemons.at(index));
    std::cout << pokemons.at(index)->get_name() + " Added To Your Team!"  <<std::endl;

    //Fin
    std::cout << "*-----------------------------------*" << std::endl;
}

std::vector<pokemon*> game_engine::select_starter_pokemon() {
    //Prise de trois pokemon au hasard et affichage 1 2 3 pour la selection derierre
    auto pokedex = pokedex::get_instance();
    
    std::vector<pokemon*> pokemons = {pokedex->get_by_id(25),pokedex->get_by_id(418),pokedex->get_by_id(396),};

    for (int i = 0; i < pokemons.size(); i++) {
        std::cout << i+1 << ": " << pokemons.at(i)->info_short() << std::endl;
    }

    return pokemons ;
}