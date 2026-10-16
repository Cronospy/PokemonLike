#include "../../includes/widgets/team_display.hpp"

#include <algorithm>
#include <iostream>
#include <string>

namespace {
    constexpr float slot_size = 150.f;
    constexpr float spacing = 15.f;

    constexpr float bar_margin = 10.f;
    constexpr float bar_height = 12.f;

    sf::Color hp_color(float ratio) {
        if (ratio > 0.5f) return {80, 200, 80};     // vert
        if (ratio > 0.2f) return {245, 176, 39};    // orange
        return {220, 50, 50};                       // rouge
    }
}

team_display::team_display(const pokemon_team& team, const sf::Vector2f& position, bool show_hp_bar)
    : position(position), show_hp_bar(show_hp_bar) {
    // Les 6 cadres sont créés une seule fois
    for (size_t i = 0; i < max_slots; ++i) {
        sf::RectangleShape frame({slot_size, slot_size});
        frame.setPosition({position.x + static_cast<float>(i) * (slot_size + spacing), position.y});
        frame.setFillColor({0, 0, 0, 120});
        frame.setOutlineColor({245, 176, 39});
        frame.setOutlineThickness(2.f);
        frames.push_back(frame);
    }
    set_team(team);
}

void team_display::set_team(const pokemon_team& team) {
    // Les sprites d'abord, puis les textures qu'ils référencent
    sprites.clear();
    textures.clear();
    hp_backgrounds.clear();
    hp_fills.clear();

    const size_t count = std::min(team.array_of_pokemons.size(), max_slots);

    for (size_t i = 0; i < count; ++i) {
        const pokemon& p = team.array_of_pokemons[i];
        const sf::Vector2f frame_pos = frames[i].getPosition();

        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile("assets/images/pokemon/" + std::to_string(p.get_id()) + ".png"))
            std::cerr << "Error: Could not load image for " << p.get_name() << std::endl;

        sf::Sprite sprite(*texture);
        auto bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.position + bounds.size / 2.f);
        sprite.setScale({2.f, 2.f});

        // Si la barre est affichée, on remonte un peu le sprite pour lui laisser la place
        const float sprite_offset_y = show_hp_bar ? -(bar_height / 2.f + 4.f) : 0.f;
        sprite.setPosition(frame_pos + sf::Vector2f{slot_size / 2.f, slot_size / 2.f + sprite_offset_y});

        textures.push_back(std::move(texture));
        sprites.push_back(sprite);

        if (show_hp_bar) {
            const float bar_width = slot_size - 2.f * bar_margin;
            const sf::Vector2f bar_pos = frame_pos + sf::Vector2f{bar_margin, slot_size - bar_margin - bar_height};

            // Protection contre une division par zéro et des PV hors bornes
            const int max_hp = p.get_max_hit_points();
            float ratio = max_hp > 0 ? static_cast<float>(p.get_hit_points()) / static_cast<float>(max_hp) : 0.f;
            ratio = std::clamp(ratio, 0.f, 1.f);

            sf::RectangleShape back({bar_width, bar_height});
            back.setPosition(bar_pos);
            back.setFillColor({40, 40, 40, 220});
            back.setOutlineColor(sf::Color::Black);
            back.setOutlineThickness(1.f);

            sf::RectangleShape fill({bar_width * ratio, bar_height});
            fill.setPosition(bar_pos);
            fill.setFillColor(hp_color(ratio));

            hp_backgrounds.push_back(back);
            hp_fills.push_back(fill);
        }
    }
}

void team_display::render(sf::RenderWindow& window) const {
    for (const auto& frame : frames) window.draw(frame);
    for (const auto& sprite : sprites) window.draw(sprite);
    for (const auto& back : hp_backgrounds) window.draw(back);
    for (const auto& fill : hp_fills) window.draw(fill);
}