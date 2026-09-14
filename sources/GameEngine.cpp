#include <iostream>

#include "../includes/GameEngine.h"

void GameEngine::startGame() {
    std::cout << "*------------ New Game ------------*" << std::endl;

    chooseStarterPokemon();

}

void GameEngine::chooseStarterPokemon() {
    std::cout << "*------ Choose Your Starter! ------*" << std::endl;

    std::vector<Pokemon*> pokemons = selectStarterPokemon();

    //Selection
    int index;
    do {
        std::cout << "*--------- Select 1,2 or 3 ---------*" << std::endl;
        std::cin >> index;
        index-=1;
    }while (index < 0 || index > pokemons.size()-1);

    //Ajout à l'equipe
    std::cout << pokemons.at(index)->get_name() + " Added To Your Team!"  <<std::endl;

    //Fin
    std::cout << "*-----------------------------------*" << std::endl;
}

std::vector<Pokemon*> GameEngine::selectStarterPokemon() {
    //Prise de trois pokemon au hasard et affichage 1 2 3 pour la selection derierre
    Pokemon pikachu(25, "Pikachu", 35, 55, 40, 1);
    Pokemon mustebouee(418, "Mustebouee",55, 65,35,4);
    Pokemon etourmi(396, "Etourmi",40, 55,30,4);
    std::vector<Pokemon*> pokemons = {&pikachu, &mustebouee, &etourmi};

    for (int i = 0; i < pokemons.size(); i++) {
        std::cout << i+1 << ": " << pokemons.at(i)->get_name() << std::endl;
    }

    return pokemons ;
}