cmake_minimum_required(VERSION 4.3)
project(PokemonLike)

set(CMAKE_CXX_STANDARD 20)

add_executable(PokemonLike main.cpp
        includes/pokemon.hpp
        sources/pokemon.cpp
        sources/set_of_pokemon.cpp
        includes/set_of_pokemon.hpp
        sources/pokedex.cpp
        includes/pokedex.hpp
        sources/game_engine.cpp
        includes/game_engine.hpp
        includes/setup.h
        sources/pokemon_team.cpp
        includes/pokemon_team.hpp)
