#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "engine/physics.h"
#include "engine/param.h"
#include "engine/sprite.h"
#include "stuff/ball.h"
#include "engine/util.h"
#pragma G++ optimize("O3")
#pragma G++ optimize("unroll-loops")

using namespace std;

vector<Ball> ballz;
vector<pair<int,int>> sprite_pos;

int main()
{

    srand(NULL);
    sf::RenderWindow window(sf::VideoMode(GAME_W, GAME_H), TITLE);
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
    Vector vcurr = Vector(0.0,0.0);
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
                    Ball kula = Ball(mx,my,vcurr);
                    ballz.push_back(kula);
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            vcurr.add(-0.75,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            vcurr.add(0.75,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            vcurr.add(0,-0.75);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            vcurr.add(0,0.75);
        }
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        Arrow arr = Arrow(pixelPos.x,pixelPos.y,vcurr);
        window.clear();
        //sprite_pos.clear();
        for(Ball &ball : ballz){
            ball.paint(window);
            //sprite_pos.emplace_back(ball.getX(),ball.getY());
        }
        //sort(sprite_pos.begin(),sprite_pos.end());
        vector<pair<int,Vector>> changes,moves;
        for(int i = 0;i<ballz.size();i++) {
            for (int j = i+1; j < ballz.size(); j++) {
                Point p2 = ballz[i].point();
                p2.x += ballz[i].v.getX();
                p2.y += ballz[i].v.getY();
                Point p3 = ballz[j].point();
                p3.x += ballz[j].v.getX();
                p3.y += ballz[j].v.getY();
                if(dist(p2,p3) <= 46){
                    /*double dx = ballz[i].getX()-ballz[j].getX();
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
                    ballz[i].move(forcea);
                    ballz[j].move(forceb);
                    ballz[j].v.mult(0.8);
                    ballz[i].v.mult(0.8);*/
                    //ballz[i].v.set((ballz[i].v.getX()+ballz[j].v.getX())*0.5,(ballz[i].v.getY()+ballz[j].v.getY())*0.5);
                    //ballz[j].v.set(-(ballz[i].v.getX()+ballz[j].v.getX())*0.5,-(ballz[i].v.getY()+ballz[j].v.getY())*0.5);
                    changes.push_back({i,Vector((ballz[i].v.getX()+ballz[j].v.getX())*0.5,(ballz[i].v.getY()+ballz[j].v.getY())*0.5)});
                    changes.push_back({j,Vector(-(ballz[i].v.getX()+ballz[j].v.getX())*0.5,-(ballz[i].v.getY()+ballz[j].v.getY())*0.5)});
                    //ballz[i].move(ballz[j].v*3.0);
                    //ballz[j].move(ballz[i].v*3.0);
                    ballz[i].v *= 0.8;
                    ballz[j].v *= 0.8;
                }
                if(dist(ballz[i].point(),ballz[j].point()) < 46){
                    //ballz[i].move(Vector(ballz[j].getX()-ballz[i].getX(),ballz[j].getY()-ballz[j].getX()));
                    moves.push_back({i,Vector(ballz[j].getX()-ballz[i].getX(),ballz[j].getY()-ballz[j].getX())});
                }
            }
        }
        for(auto &[ind,vec] : changes){
            ballz[ind].v.set(vec);
        }
        for(auto &[ind,vec] : moves){
            ballz[ind].move(vec);
        }
        arr.paint(window);
        window.display();
    }
    return 0;
}