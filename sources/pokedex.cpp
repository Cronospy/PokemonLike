#include "../includes/pokedex.hpp"
#include "../includes/setup.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

pokedex* pokedex::instance = nullptr;

pokedex::pokedex():set_of_pokemon() {

    std::cout << "*** Constructeur du pokedex ***" << std::endl;

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

        array_of_pokemons.push_back(new pokemon(id,name,max_hit_point,attack,defense,generation));
    }
    instance = this;
}

pokedex* pokedex::get_instance() {
    if (instance==nullptr) {
        instance = new pokedex();
    }
    return instance;
}