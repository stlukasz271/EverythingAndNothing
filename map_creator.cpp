#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "engine/physics.h"
#include "param.h"
#include "engine/sprite.h"
#include "stuff/ball.h"
#include "engine/util.h"
#include "engine/menus.h"
#include "engine/map_manager.h"
#pragma G++ optimize("O3")
#pragma G++ optimize("unroll-loops")

using namespace std;

typedef pair<int,int> pint;

struct SpriteInfo{
    string name,image,other;
    double x,y;
};

int curr_layer = 1;
vector<SpriteInfo> sprites;
map<pint,SpriteInfo> layers[10];

int main()
{

    srand(NULL);
    sf::RenderWindow window(sf::VideoMode(GAME_W, GAME_H), TITLE);
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
    setup_once();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    double mx = pixelPos.x;
                    double my = pixelPos.y;
                }
            }
        }
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        }*/
        window.clear();

        window.display();
    }
    return 0;
}