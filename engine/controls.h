#pragma once
#include<bits/stdc++.h>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Graphics.hpp>
#include "../param.h"

using namespace std;

int buttons[100003],keys[100003];
bool SHIFT = false, CONTROL = false, ALT = false;
bool leftpressed=false,rightpressed=false,middlepressed=false;
double MOUSEX=0.0,MOUSEY=0.0;

sf::Event event;

bool leftPressed(){
    return leftpressed;
}

bool rightPressed(){
    return rightpressed;
}

bool middlePressed(){
    return middlepressed;
}

void listen(sf::RenderWindow &window){
    leftpressed=false;rightpressed=false;middlepressed=false;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            EXIT = 1;
        }
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        MOUSEX = pixelPos.x;
        MOUSEY = pixelPos.y;
        leftpressed=false;rightpressed=false;middlepressed=false;
        if (event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == sf::Mouse::Middle){
                middlepressed = true;
            }else{
                middlepressed=false;
            }
            if(event.mouseButton.button == sf::Mouse::Right){
                rightpressed = true;
            }else{
                rightpressed=false;
            }
            if(event.mouseButton.button == sf::Mouse::Left){
                leftpressed = true;
            }else{
                leftpressed=false;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed){
            buttons[event.mouseButton.button] = 1;
        }
        if (event.type == sf::Event::MouseButtonReleased){
            buttons[event.mouseButton.button] = 0;
        }
        if (event.type == sf::Event::KeyPressed){
            keys[event.key.code] = 1;
            if(event.key.alt){ALT = true;}
            if(event.key.shift){SHIFT = true;}
            if(event.key.control){CONTROL = true;}
        }
        if (event.type == sf::Event::KeyReleased){
            keys[event.key.code] = 0;
            if(event.key.alt){ALT = false;}
            if(event.key.shift){SHIFT = false;}
            if(event.key.control){CONTROL = false;}
        }
    }
}