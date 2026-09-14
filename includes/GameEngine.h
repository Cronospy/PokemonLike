#include <vector>

#include "pokemon.hpp"

class GameEngine {
    private:
        std::pmr::vector<Pokemon*> pokemonTeam;

    public:
        GameEngine() = default;
        void startGame();
        void chooseStarterPokemon();
        std::vector<Pokemon*> selectStarterPokemon();
};
