#pragma once
#include "../engine/sprite.h"
#include "../engine/util.h"
#include<bits/stdc++.h>
#include<SFML/Window.hpp>

using namespace std;

const string BALLPATH = ASSETPATH+"ball.png";

class Ball : public Sprite{
    private:
        int index=0;
        bool last = false;
    public:
        void assignIndex(int index, bool last){
            this->index=index;
            this->last=last;
        }
        void handleCollision(vector<Ball> balls){
            return;
        }
        Ball(double x, double y) : Sprite(x,y,BALLPATH){
            v.set(0.1*randint(-100,100),0);
            a.set(-v.getX()/500.0,G_ACC);
        }
    protected:
        void childPaint(sf::RenderWindow &window){
            Arrow arr(getX()+24,getY()+24,mult(v,20));
            arr.paint(window);
            Arrow arr2(getX()+24,getY()+24,mult(a,50), sf::Color(0,255,0));
            arr2.paint(window);
            if(abs(v.getX())<=EPS){
                v.nulX();
                a.nulX();
            }else{
                a.set(-v.getX()/300.0,G_ACC);
            }
            if(getY()+48 >= GAME_H){
                addY(-v.getY());
                v.multY(-0.80);
            }
            if(getX()+48 >= GAME_W || getX()-EPS <= 0){
                addX(-v.getX());
                v.multX(-0.80);
            }
            if(abs(v.getY())<=EPS){
                v.nulY();
            }
        }
};

