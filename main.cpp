#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "algo/trie.h"
#include "engine/sprite.h"
#include "engine/param.h"

using namespace std;

vector<Sprite> ballz;

int main()
{

    srand(NULL);
    sf::RenderWindow window(sf::VideoMode(GAME_W, GAME_H), TITLE);

    for(int i = ((640-48)%52)/2;i+48<=GAME_W;i+=52){
        Sprite ten(i,20,ASSETPATH+"ball.png");
        ten.v.set(0.01*randint(-20,20),0);
        ten.a.set(-ten.v.getX()/100.0,G_ACC);
        ballz.push_back(ten);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(Sprite &ball : ballz){
            ball.paint(window);
            if(abs(ball.v.getX())<EPS){
                ball.v.set(0.0,ball.v.getY());
                ball.a.set(0.0,ball.a.getY());
            }
        }
        window.display();
        window.setFramerateLimit(60);
    }
    return 0;
}