#pragma once
#include <string>
using std::string;

// Commentary to describe the Pokemon class

class pokemon {
private:
    int id;
    string name;
    int hit_points;
    int max_hit_points;
    int attack;
    int defense;
    int generation;

public:
    pokemon(int id, const string& name,int max_hit_points, int attack, int defense, int generation);
    pokemon(const pokemon& other);
    ~pokemon();

    int get_id() const;
    string get_name() const;
    int get_hit_points() const;
    int get_attack() const;
    int get_defense() const;

    void set_hit_points(int hit_points);

    void display_all() const;
    string info_short() const;
    void attack_on(pokemon& pokemon_attacked) const;
    void full_heal();
};