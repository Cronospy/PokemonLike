#pragma once
#include "game_states.hpp"
#include <memory>
#include "../widgets/pokemon_choice_button.hpp"

#include <SFML/Graphics.hpp>
using namespace sf;

class starter_state : public game_states {
    private:
        Texture background_texture;
        Font instruction_font;

        std::vector<std::unique_ptr<pokemon_choice_button>> starter_buttons;

    public:
        starter_state();
        void update() override;
        void render() override;

        void set_background();
        void title_draw();
};