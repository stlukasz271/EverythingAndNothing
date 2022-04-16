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

    for(int i = ((640-48)%52)/2;i+48<=GAME_W;i+=104){
        Sprite ten(i,20,ASSETPATH+"ball.png");
        ten.v.set(0.1*randint(-20,20),0);
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
            for(Sprite &ball2 : ballz){
                if(dist(ball.point(),ball2.point()) <= 24.0){
                    /*Vector r_force((ball2.getX()-ball.getX())/min(ball2.getX(),ball.getX()),(ball2.getY()-ball.getY())/min(ball2.getY(),ball.getY()));
                    r_force.mult(-ball.v.len());
                    ball.addX(r_force.getX());
                    ball.addY(r_force.getY());
                    ball.v.add(r_force);*/
                }
            }
        }
        window.display();
        window.setFramerateLimit(60);
    }
    return 0;
}