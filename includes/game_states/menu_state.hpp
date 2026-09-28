#pragma once
#include "game_states.hpp"
#include "../widgets/button.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class menu_state : public game_states {
    private:
        sf::Texture background_texture;
        sf::Texture locklass_texture;
        sf::Texture flambusard_texture;
        sf::Texture ouvrifier_texture;
        sf::Font title_font;

        std::unique_ptr<button> play_btn;
    public:
        menu_state();
        void update() override;
        void render() override;

        void set_background();
        void title_draw();
        void locklass_draw();
        void flambusard_draw();
        void ouvrifier_draw();
};