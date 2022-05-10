#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "engine/physics.h"
#include "param.h"
#include "engine/sprite.h"
#include "stuff/ball.h"
#include "engine/util.h"
#include "engine/menus.h"
#include "engine/map_manager.h"
#include "engine/controls.h"

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
    setup_once();

    Vector vcurr = Vector(0.0,0.0);
    Caption subtitle = Caption(-1,0,"NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                    "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                    "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                    "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                    "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                    "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                    "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                    "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                    "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                    );
    subtitle.animate = true;
    subtitle.anim_interval = 1;
    subtitle.loops = -1;
    Caption subtitle2 = Caption(-1,subtitle.getMaxH()+100,"NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                                          "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                                          "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                                          "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                                          "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                                          "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                                          "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                                          "NIGGER !!! NIGGER !!! NIGGER !!!\n"
                                                          "NIGGER !!! NIGGER !!! NIGGER !!!\n"
    );
    subtitle2.animate = true;
    subtitle2.anim_interval = 1;
    subtitle2.loops = -1;
    FieldOfText title = FieldOfText(0,subtitle.getMaxH()+2, GAME_W, 95, "N I G G E R !!!", sf::Color(50,50,50),sf::Color(100,100,100),false,-1,sf::Color::White,DEF_FONT,59);
    title.caption.animate = true;
    title.caption.anim_interval = 9;
    title.caption.loops = 0;
    MapLoader ml = MapLoader();
    ml.setInput(R"(C:\Users\Public\Documents\Projects\EverythingAndNothing\maps\test_map.txt)");
    vector<Sprite> vspr = ml.loadSprites();
    while (window.isOpen()) {
        if(EXIT){
            return 0;
        }
        listen(window);
        if(leftPressed()){
            Ball kula = Ball(MOUSEX,MOUSEY,vcurr);
            ballz.push_back(kula);
        }
        if (keys[sf::Keyboard::Left]){
            vcurr.add(-0.75,0);
        }
        if (keys[sf::Keyboard::Right]){
            vcurr.add(0.75,0);
        }
        if (keys[sf::Keyboard::Up]){
            vcurr.add(0,-0.75);
        }
        if (keys[sf::Keyboard::Down]){
            vcurr.add(0,0.75);
        }
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        Arrow arr = Arrow(pixelPos.x,pixelPos.y,vcurr);
        window.clear();
        arr.paint(window);
        subtitle.centerX();
        subtitle.paint(window);
        subtitle2.centerX();
        subtitle2.paint(window);
        //title.centerX();
        title.paint(window);
        title.centerText();
        for(Ball &ball : ballz){
            ball.paint(window);
        }
        for(Sprite &spr : vspr){
            spr.paint(window);
        }
        window.display();
    }
    return 0;
}