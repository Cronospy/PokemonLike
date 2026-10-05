#pragma once

#include <SFML/Graphics.hpp>

#include "events.hpp"
#include "../widgets/button.hpp"
#include "../player.hpp"
#include "../widgets/team_display.hpp"

class pokecenter_event : public events {
    private:
        player* current_player;

        Texture background_texture;
        Font title_font;

        Texture wild_pokemon_texture;

        std::unique_ptr<button> heal_button;
        std::unique_ptr<team_display> team_widget;
    public:
        pokecenter_event(player* player);

        void update(const sf::RenderWindow& window) override;
        void render(sf::RenderWindow& window) override;

        void set_background(sf::RenderWindow& window);
};
