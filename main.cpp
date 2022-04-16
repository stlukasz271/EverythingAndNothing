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
    window.setVerticalSyncEnabled(true);
    for(int i = ((640-48)%52)/2;i+48<=GAME_W;i+=104){
        Ball ten(i,20);
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
        if (!is_sorted(ballz.begin(), ballz.end())) {
            sort(ballz.begin(), ballz.end());
        }
        for(Sprite &ball : ballz){
            ball.paint(window);
            if(abs(ball.v.getX())<EPS){
                ball.v.nulX();
                ball.a.nulX();
            }
            if(ball.getY()+48 >= GAME_H){
                ball.addY(-ball.v.getY());
                ball.v.multY(-0.80);
            }
            if(ball.getX()+48 >= GAME_W || ball.getX()-EPS <= 0){
                ball.addX(-ball.v.getX());
                ball.v.multX(-0.80);
            }
        }
        window.display();
        window.setFramerateLimit(60);
    }
    return 0;
}