#include "../../includes/sets_of_pokemon/pokedex.hpp"
#include "../../includes/setup.h"
#include "../../includes/pokemon.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <random>

pokedex* pokedex::instance = nullptr;

pokedex::pokedex():set_of_pokemon() {

    //std::cout << "*** Constructeur du pokedex ***" << std::endl;

    string file_name = CSV_POKEDEX_FILE;

    std::ifstream file(file_name);
    if(!file.is_open()){
        std::cerr<<"File "<<file_name<<" not found "<<std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        //    std::cout << line << std::endl;
        std::stringstream inputstringstream(line);
        std::string cell;
        std::vector<std::string> lineData;

        while(std::getline(inputstringstream,cell,',')){
            lineData.push_back(cell);
        }

        int id = std::stoi(lineData.at(0));
        string name = lineData.at(1);
        int attack = std::stoi(lineData.at(6));
        int max_hit_point = std::stoi(lineData.at(5));
        int defense = std::stoi(lineData.at(7));
        int generation = std::stoi(lineData.at(11));

        array_of_pokemons.push_back(pokemon(id,name,max_hit_point,attack,defense,generation));
    }
    instance = this;
}

pokedex* pokedex::get_instance() {
    if (instance==nullptr) {
        instance = new pokedex();
    }
    return instance;
}

pokemon pokedex::get_by_id(int id) {
    for (pokemon pokemon : array_of_pokemons) {
        if (pokemon.get_id() == id) {
            return pokemon;
        }
    }
    throw std::invalid_argument("Pokemon not found");
}

pokemon pokedex::get_by_name(const std::string& name) {
    for (pokemon pokemon : array_of_pokemons) {
        if (pokemon.get_name() == name) {
            return pokemon;
        }
    }
    throw std::invalid_argument("Pokemon not found");
}

pokemon pokedex::get_random_pokemon() const {
    if (array_of_pokemons.empty()) {
        std::cerr << "Pokemon is empty" << std::endl;
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, array_of_pokemons.size() - 1);

    return array_of_pokemons[dist(gen)];
}
