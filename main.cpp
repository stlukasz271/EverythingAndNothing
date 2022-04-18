#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "engine/physics.h"
#include "engine/param.h"
#include "engine/sprite.h"
#include "stuff/ball.h"

using namespace std;

vector<Ball> ballz;

int main()
{

    srand(NULL);
    sf::RenderWindow window(sf::VideoMode(GAME_W, GAME_H), TITLE);
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
    for(int i = ((640-48)%30)/2;i+48<=GAME_W;i+=60){
        Ball ten(i,randint(0,50));
        ballz.push_back(ten);
    }
    for(int i = ((640-48)%30)/2;i+48<=GAME_W;i+=60){
        Ball ten(i,randint(0,75));
        ballz.push_back(ten);
    }
    for(int i = ((640-48)%30)/2;i+48<=GAME_W;i+=60){
        Ball ten(i,randint(0,100));
        ballz.push_back(ten);
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
        }
        window.clear();
        for(Ball &ball : ballz){
            ball.paint(window);
        }
        window.display();
    }
    return 0;
}