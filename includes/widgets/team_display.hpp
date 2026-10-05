#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "../sets_of_pokemon/pokemon_team.hpp"

class team_display {
    private:
        static constexpr size_t max_slots = 6;

        sf::Vector2f position;
        bool show_hp_bar;

        std::vector<sf::RectangleShape> frames;
        std::vector<std::unique_ptr<sf::Texture>> textures;
        std::vector<sf::Sprite> sprites;
        std::vector<sf::RectangleShape> hp_backgrounds;
        std::vector<sf::RectangleShape> hp_fills;

    public:
        team_display(const pokemon_team& team, const sf::Vector2f& position, bool show_hp_bar = true);

        void set_team(const pokemon_team& team);

        void render(sf::RenderWindow& window) const;
};