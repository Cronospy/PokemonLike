#include <memory>

#include "../includes/player.hpp"

player::player() {
    team = std::make_unique<pokemon_team>();
    box = std::make_unique<pokemon_box>();
};

pokemon_box &player::get_box() {
    return *box;
}

pokemon_team &player::get_team() {
    return *team;
}

