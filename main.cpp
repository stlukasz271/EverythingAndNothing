#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "algo/trie.h"
#include "engine/sprite.h"
#include "engine/param.h"
#include<SFML/System.hpp>

using namespace std;

vector<Sprite> ballz;

int main()
{

    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(GAME_W, GAME_H), TITLE);
    for(int i = ((640-48)%52)/2;i+48<=GAME_W;i+=52){
        Sprite ten(i,20,ASSETPATH+"ball.png");
        ten.setV(0.01*randint(-20,20),0);
        ten.setA(-ten.getV().first/100.0,G_ACC);
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
            if(abs(ball.getV().first)<EPS){
                ball.setV(0.0,ball.getV().second);
                ball.setA(0.0,ball.getA().second);
            }
        }
        window.display();
        window.setFramerateLimit(60);
    }
    return 0;
}