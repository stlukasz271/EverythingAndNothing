#pragma once

#include<bits/stdc++.h>
#include <string>
#include "sprite.h"
#include "util.h"
#include "../stuff/tile.h"

using namespace std;

class MapLoader{
    public:
        void setInput(const char* path){
            freopen(path, "r", stdin);
        }
        vector<Sprite> loadSprites(){
            vector<Sprite> res;
            string type;
            while(cin>>type){
                if(type == "TILE"){
                    int n_params,n_tex;
                    vector<string> textures;
                    cin>>n_tex;
                    for(int i = 1;i<=n_tex;i++){
                        string tex;
                        cin>>tex;
                        textures.push_back(ASSETPATH+tex);
                    }
                    cin>>n_params;
                    vector<double> params;
                    for(int i = 1;i<=n_params;i++){
                        double x;
                        cin>>x;
                        params.push_back(x);
                    }
                    Tile this_tile = Tile(textures,params);
                    res.push_back(this_tile);
                }
            }
            return res;
        }
};