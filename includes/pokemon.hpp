#include <string>
using std::string;

// Commentary to describe the Pokemon class

class Pokemon {
private:
    int id;
    string name;
    int hit_points;
    int max_hit_points;
    int attack;
    int defense;
    int generation;

public:
    Pokemon(int id, const string& name,int max_hit_points, int attack, int defense, int generation);
    Pokemon(const Pokemon& other);
    ~Pokemon();

    int get_id() const;
    string get_name() const;
    int get_hit_points() const;
    int get_attack() const;
    int get_defense() const;

    void set_hit_points(int hit_points);

    void displayAll() const;
    void displayShort() const;
    void attack_on(Pokemon& pokemon_attacked) const;
    void full_heal();
};