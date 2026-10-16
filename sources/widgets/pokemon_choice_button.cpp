#include "../../includes/widgets/pokemon_choice_button.hpp"

#include <iostream>


pokemon_choice_button::pokemon_choice_button(const pokemon &pokemon, const sf::Font &font, const sf::Vector2f &position)
    : button(font, pokemon.get_name(),sf::Vector2f{180.f, 180.f}, position),
    chosen_pokemon(pokemon),
    pokemon_sprite(pokemon_texture)
    {
    std::string path = "assets/images/pokemon/"+std::to_string(pokemon.get_id())+".png";
    if (!pokemon_texture.loadFromFile(path)) {
        std::cerr << "Error: Could not load image for " << pokemon.get_name() << std::endl;
    }

    pokemon_sprite.setTexture(pokemon_texture,true);
    auto bounds = pokemon_sprite.getLocalBounds();
    pokemon_sprite.setOrigin(bounds.position + bounds.size / 2.f);

    pokemon_sprite.setPosition(position);
    pokemon_sprite.setScale(sf::Vector2f{3,3});
}

void pokemon_choice_button::render(RenderWindow &window) const {
    window.draw(this->get_shape());
    window.draw(pokemon_sprite);
}
