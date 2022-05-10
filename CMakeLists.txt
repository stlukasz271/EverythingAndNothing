cmake_minimum_required(VERSION 3.22)
project(EverythingAndNothing)

set(CMAKE_CXX_STANDARD 20)

add_executable(EverythingAndNothing main.cpp algo/trie.h param.h engine/sprite.h engine/physics.h stuff/ball.h engine/util.h engine/menus.h engine/map_manager.h stuff/tile.h engine/controls.h)
add_executable(MapEditor map_creator.cpp algo/trie.h param.h engine/sprite.h engine/physics.h stuff/ball.h engine/util.h engine/menus.h engine/map_manager.h stuff/tile.h engine/controls.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(EverythingAndNothing sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(MapEditor sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
