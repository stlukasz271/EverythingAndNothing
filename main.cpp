#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "engine/physics.h"
#include "engine/param.h"
#include "engine/sprite.h"
#include "stuff/ball.h"
#pragma G++ optimize("O3")
#pragma G++ optimize("unroll-loops")

using namespace std;

vector<Ball> ballz;

int main()
{

    srand(NULL);
    sf::RenderWindow window(sf::VideoMode(GAME_W, GAME_H), TITLE);
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
    for(int i = ((640-48)%60)/2;i+48<=GAME_W;i+=120){
        Ball ten(i,randint(0,50));
        ballz.push_back(ten);
    }
    /*for(int i = ((640-48)%30)/2;i+48<=GAME_W;i+=60){
        Ball ten(i,randint(0,75));
        ballz.push_back(ten);
    }
    for(int i = ((640-48)%30)/2;i+48<=GAME_W;i+=60){
        Ball ten(i,randint(0,100));
        ballz.push_back(ten);
    }*/
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
        for(int i = 0;i<ballz.size();i++) {
            for (int j = i+1; j < ballz.size(); j++) {
                if(dist(ballz[i].point(),ballz[j].point()) <= 48){
                    double dx = ballz[i].getX()-ballz[j].getX();
                    double dy = ballz[i].getY()-ballz[j].getY();
                    double tga = dy/dx;
                    double sina = tga/sqrt((tga*tga)+1);
                    double cosa = sina/tga;
                    double d = 3.0;//sqrt(ballz[i].v.len());//4.0;
                    double d2 = 3.0;//sqrt(ballz[j].v.len());;
                    Vector forcea = Vector(d*cosa,d*sina);
                    ballz[i].v.add(forcea);
                    Vector forceb = Vector(-d2*cosa,-d2*sina);
                    ballz[j].v.add(forceb);
                    //ballz[i].move(forcea);
                   // ballz[j].move(forceb);
                }
            }
        }
        window.display();
    }
    return 0;
}