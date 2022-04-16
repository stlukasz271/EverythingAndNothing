#pragma once
#include "../engine/sprite.h"
#include<bits/stdc++.h>

using namespace std;

const string BALLPATH = ASSETPATH+"ball.png";

class Ball : public Sprite{
    public:
        Ball(double x, double y) : Sprite(x,y,BALLPATH){
            v.set(0.1*randint(-20,20),0);
            a.set(-v.getX()/500.0,G_ACC);
        }
};

