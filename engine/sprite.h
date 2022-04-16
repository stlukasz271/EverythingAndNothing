#include "physics.h"

using namespace std;

class Sprite{

    private:
        double x=0,y=0,dx=0,dy=0,ax=0,ay=0,smooth=true;
        int frame=0,anim=0;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;
        vector<vector<string>> paths;
    public:
        Vector v = Vector(0.0,0.0), a = Vector(0.0,0.0);
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
        void setX(double x){
            this->x=x;
        }
        void setY(double y){
            this->y=y;
        }
        void set(double x, double y){
            this->x=x;
            this->y=y;
        }
        void nul(){
            set(0.0,0.0);
        }
        void nulX(){
            setX(0.0);
        }
        void nulY(){
            setY(0.0);
        }
        void addX(double x){
            setX(this->x+x);
        }
        void addY(double y){
            setY(this->y+y);
        }
        Point point(){
            return {getX(),getY()};
        }
        string getPath(){
            return paths[anim][frame];
        }
        Sprite(double x, double y, string path,bool smooth = true){
            this->x=x;
            this->y=y;
            this->smooth=smooth;
            vector<string> tmp({path});
            paths.push_back(tmp);
        }
        Sprite(double x, double y, vector<vector<string>> paths,bool smooth = true){
            this->x=x;
            this->y=y;
            this->smooth=smooth;
            this->paths = paths;
        }
        void paint(sf::RenderWindow &window){
            v.add(a);
            x+=v.getX();
            y+=v.getY();
            image.loadFromFile(getPath());
            texture.loadFromImage(image);
            texture.setSmooth(true);
            sprite.setPosition(x,y);
            sprite.setTexture(texture, true);
            window.draw(sprite);
        }

};