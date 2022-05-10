#pragma once
#include<bits/stdc++.h>
#include "../engine/sprite.h"

using namespace std;

class Tile : public Sprite{
    public:
        Tile(vector<string> textures, vector<double> args) : Sprite(args[0],args[1],vector<vector<string>> ({textures})){
            if(args.size()>2){
                w = args[2];
                h = args[3];
            }
        }
};