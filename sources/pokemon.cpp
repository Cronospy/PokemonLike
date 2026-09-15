#include "../includes/pokemon.hpp"

#include <string>
using std::string;
#include <iostream>

pokemon::pokemon(int id, const string& name,int max_hit_points,  int attack, int defense, int generation)
    : id(id), name(name), hit_points(max_hit_points), max_hit_points(max_hit_points), attack(attack), defense(defense), generation(generation) {}
        
pokemon::pokemon(const pokemon& other)
    : id(other.id), name(other.name), hit_points(other.max_hit_points), max_hit_points(max_hit_points), attack(other.attack), defense(other.defense), generation(other.generation) {}

pokemon::~pokemon() = default;

int pokemon::get_id() const {
    return id;
}

string pokemon::get_name() const {
    return name;
}

int pokemon::get_hit_points() const {
    return hit_points;
}

int pokemon::get_attack() const {
    return attack;
}

int pokemon::get_defense() const {
    return defense;
}

void pokemon::set_hit_points(int new_hit_points) {
    hit_points = new_hit_points;
}

void pokemon::display_all() const {
    std::cout<<"ID: "<< id << std::endl;
    std::cout<<"Name: "<< name << std::endl;
    std::cout<<"Hit Points: "<< hit_points << std::endl;
    std::cout<<"Attack: "<< attack << std::endl;
    std::cout<<"Defense: "<< defense << std::endl;
    std::cout<<"Generation: "<< generation << std::endl;
}

string pokemon::info_short() const {
    return name + " | HP: " + std::to_string(hit_points)
                 + " ATK: " + std::to_string(attack)
                 + " DEF: " + std::to_string(defense);
}

void pokemon::attack_on(pokemon& pokemon_attacked) const {
    int atk_def_diff = attack - pokemon_attacked.get_defense();
    if (atk_def_diff > 0) {
        pokemon_attacked.set_hit_points(pokemon_attacked.get_hit_points() - atk_def_diff);
        if (pokemon_attacked.get_hit_points() <= 0) {
            pokemon_attacked.set_hit_points(0);
            std::cout<< pokemon_attacked.get_name() + " fainted!" <<std::endl;
        }
    }
}

void pokemon::full_heal() {
    hit_points = max_hit_points;
}