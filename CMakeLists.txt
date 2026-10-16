cmake_minimum_required(VERSION 4.3)
set(CMAKE_POLICY_VERSION_MINIMUM "3.5" CACHE STRING "" FORCE)
project(PokemonLike)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG master
)
FetchContent_MakeAvailable(SFML)

add_executable(PokemonLike main.cpp
        includes/pokemon.hpp
        sources/pokemon.cpp
        sources/sets_of_pokemon/set_of_pokemon.cpp
        includes/sets_of_pokemon/set_of_pokemon.hpp
        sources/sets_of_pokemon/pokedex.cpp
        includes/sets_of_pokemon/pokedex.hpp
        sources/game_engine.cpp
        includes/game_engine.hpp
        includes/setup.h
        sources/sets_of_pokemon/pokemon_team.cpp
        includes/sets_of_pokemon/pokemon_team.hpp
        sources/events/wild_pokemon_event.cpp
        includes/events/wild_pokemon_event.hpp
        sources/events/events.cpp
        includes/events/events.hpp
        sources/game_states/game_states.cpp
        includes/game_states/game_states.hpp
        sources/game_states/menu_state.cpp
        includes/game_states/menu_state.hpp
        sources/game_states/starter_state.cpp
        includes/game_states/starter_state.hpp
        sources/game_states/playing_state.cpp
        includes/game_states/playing_state.hpp
        sources/game_states/win_state.cpp
        includes/game_states/win_state.hpp
        sources/game_states/game_over_state.cpp
        includes/game_states/game_over_state.hpp
        sources/sets_of_pokemon/pokemon_box.cpp
        includes/sets_of_pokemon/pokemon_box.hpp
        sources/player.cpp
        includes/player.hpp
        sources/widgets/button.cpp
        includes/widgets/button.hpp
        sources/widgets/pokemon_choice_button.cpp
        includes/widgets/pokemon_choice_button.hpp
        sources/widgets/team_display.cpp
        includes/widgets/team_display.hpp
        sources/events/pokecenter_event.cpp
        includes/events/pokecenter_event.hpp
        sources/events/trainer_event.cpp
        includes/events/trainer_event.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
        SFML::Graphics
        SFML::Audio
        SFML::Window
        SFML::System
)
