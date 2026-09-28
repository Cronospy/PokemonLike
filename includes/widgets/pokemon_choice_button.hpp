#pragma once

#include "button.hpp"
#include "../pokemon.hpp"

class pokemon_choice_button : public button {
    private:
        pokemon chosen_pokemon;

        Texture pokemon_texture;
        Sprite pokemon_sprite;
    public:
        pokemon_choice_button(const pokemon& pokemon, const sf::Font& font, const sf::Vector2f& position);

        void render(sf::RenderWindow& window) const;
};