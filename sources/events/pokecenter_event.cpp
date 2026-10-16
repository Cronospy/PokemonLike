#include "../../includes/events/pokecenter_event.hpp"
#include <iostream>

pokecenter_event::pokecenter_event(player *player) : current_player(player) {
    if (!background_texture.loadFromFile("assets/images/pokecenter_bg.png"))
        std::cout << "Error: Could not display background image" << std::endl;
    if (!title_font.openFromFile("assets/fonts/fiftiesMovies.ttf"))
        std::cout << "Can't find the font file" << std::endl;

    heal_button = std::make_unique<button>(title_font,"Heal !",sf::Vector2f{400.f, 150.f},sf::Vector2f{460.f, 550.f});
    heal_button->set_on_click([this]()-> void {
        current_player->get_team().heal_all_pokemons();
        finish();
    });
    heal_button->set_default_color(Color::Green);
    heal_button->set_hover_color({0,255,0,150});

}

void pokecenter_event::update(const sf::RenderWindow &window) {
    if (!team_widget) {
        team_widget = std::make_unique<team_display>(
            current_player->get_team(), sf::Vector2f{112.f, 20.f});
    }
    heal_button->update(window);
}

void pokecenter_event::render(sf::RenderWindow &window) {
    set_background(window);
    if (team_widget) team_widget->render(window);
    heal_button->render(window);
}

void pokecenter_event::set_background(sf::RenderWindow &window) {
    Sprite backgroundImage(background_texture);

    backgroundImage.setTexture(background_texture, true);
    window.draw(backgroundImage);
}
