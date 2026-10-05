#pragma once
#include "set_of_pokemon.hpp"
#include <memory>

class pokedex : public set_of_pokemon{
    private:
        static pokedex* instance;
        pokedex();
    public:
        static pokedex *get_instance();

        pokemon get_by_id(int id) override;
        pokemon get_by_name(const std::string& name) override;

        pokemon get_random_pokemon() const;
};
