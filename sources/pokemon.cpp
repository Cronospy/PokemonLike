#include "../includes/pokemon.hpp"

#include <string>
using std::string;
#include <iostream>

Pokemon::Pokemon(int id, const string& name,int max_hit_points,  int attack, int defense, int generation)
    : id(id), name(name), hit_points(max_hit_points), max_hit_points(max_hit_points), attack(attack), defense(defense), generation(generation) {}
        
Pokemon::Pokemon(const Pokemon& other)
    : id(other.id), name(other.name), hit_points(other.max_hit_points), max_hit_points(max_hit_points), attack(other.attack), defense(other.defense), generation(other.generation) {}

Pokemon::~Pokemon() = default;

int Pokemon::get_id() const {
    return id;
}

string Pokemon::get_name() const {
    return name;
}

int Pokemon::get_hit_points() const {
    return hit_points;
}

int Pokemon::get_attack() const {
    return attack;
}

int Pokemon::get_defense() const {
    return defense;
}

void Pokemon::set_hit_points(int new_hit_points) {
    hit_points = new_hit_points;
}

void Pokemon::displayAll() const {
    std::cout<<"ID: "<< id << std::endl;
    std::cout<<"Name: "<< name << std::endl;
    std::cout<<"Hit Points: "<< hit_points << std::endl;
    std::cout<<"Attack: "<< attack << std::endl;
    std::cout<<"Defense: "<< defense << std::endl;
    std::cout<<"Generation: "<< generation << std::endl;
}

void Pokemon::displayShort() const {
    std::cout<< name << " HP: " << hit_points <<" atk: " << attack << " def: " << defense<< std::endl;
}

void Pokemon::attack_on(Pokemon& pokemon_attacked) const {
    int atk_def_diff = attack - pokemon_attacked.get_defense();
    if (atk_def_diff > 0) {
        pokemon_attacked.set_hit_points(pokemon_attacked.get_hit_points() - atk_def_diff);
        if (pokemon_attacked.get_hit_points() <= 0) {
            pokemon_attacked.set_hit_points(0);
            std::cout<< pokemon_attacked.get_name() + " fainted!" <<std::endl;
        }
    }
}

void Pokemon::full_heal() {
    hit_points = max_hit_points;
}