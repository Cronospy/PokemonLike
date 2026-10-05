#pragma once

#include "player.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class game_states;

class game_engine {
    private:
        std::unique_ptr<game_states> current_state;
        std::unique_ptr<game_states> pending_state;
        player current_player;
        sf::RenderWindow* window = nullptr;

    public:
        game_engine(std::unique_ptr<game_states> initial_state, sf::RenderWindow *window);

        void update();
        void render();

        void set_game_state(std::unique_ptr<game_states> new_state);

        sf::RenderWindow* get_window();

        player* get_player();
};
