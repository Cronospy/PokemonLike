#include "../../includes/game_states/starter_state.hpp"
#include "../../includes/game_engine.hpp"
#include "../../includes/sets_of_pokemon/pokedex.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../includes/game_states/menu_state.hpp"
#include "../../includes/game_states/playing_state.hpp"

using namespace std;

starter_state::starter_state() {
    if (!background_texture.loadFromFile("assets/images/starter_bg.png"))
        std::cout << "Error: Could not display background image" << std::endl;
    if (!instruction_font.openFromFile("assets/fonts/fiftiesMovies.ttf"))
        std::cout << "Can't find the font file" << std::endl;


    const auto pokedex = pokedex::get_instance();
    const std::vector<int> ids = {387, 390, 393};

    for (int i = 0; i < static_cast<int>(ids.size()); ++i) {
        float x_start = 195.0f;
        int id = ids[i];

        pokemon p = pokedex->get_by_id(id);
        auto btn = std::make_unique<pokemon_choice_button>(
            p, instruction_font, sf::Vector2f{x_start + i * 410.f, 605.f}
        );

        btn->set_on_click([this, id]() {
            auto pokedex = pokedex::get_instance();
            pokemon chosen = pokedex->get_by_id(id);
            engine->get_player()->get_team().add_pokemon(chosen);
            engine->set_game_state(std::make_unique<playing_state>(engine));
        });

        btn->set_default_color({0,0,0,0});
        btn->set_hover_color({245, 176, 39,150});

        starter_buttons.push_back(std::move(btn));
    }
}

void starter_state::update() {
    for (auto &button : starter_buttons) {
        button->update(*engine->get_window());
    }
}

void starter_state::render() {
    set_background();
    title_draw();
    for (auto &button : starter_buttons) {
        button->render(*engine->get_window());
    }
}

void starter_state::set_background() {
    sf::Sprite backgroundImage(background_texture);

    backgroundImage.setTexture(background_texture, true);
    engine->get_window()->draw(backgroundImage);
}

void starter_state::title_draw() {
    sf::Text title_text(instruction_font, std::string("Choose your starter"));
    title_text.setStyle(Text::Bold);
    title_text.setFillColor({0, 0, 0});
    title_text.setCharacterSize(74);
    title_text.setPosition({250,100});

    engine->get_window()->draw(title_text);
}
