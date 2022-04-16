cmake_minimum_required(VERSION 3.22)
project(HelloSFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(EverythingAndNothing main.cpp algo/trie.h engine/param.h engine/sprite.h engine/physics.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(EverythingAndNothing sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
