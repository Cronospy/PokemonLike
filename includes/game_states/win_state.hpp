#pragma once

#include <SFML/Graphics.hpp>

#include "../game_states/game_states.hpp"
#include "../widgets/team_display.hpp"


class win_state : public game_states {
    private:
        sf::Texture background_texture;
        sf::Font title_font;

        std::unique_ptr<team_display> team_widget;

    public:
        win_state(game_engine* engine);

        void update() override;
        void render() override;

        void set_background();
        void title_draw();
};
