#pragma once
#include "../engine/sprite.h"
#include<bits/stdc++.h>

using namespace std;

const string BALLPATH = "../assets/ball.png";

class Ball : public Sprite{
    public:
        Ball(double x, double y) : Sprite(x,y,BALLPATH){

        }
};

