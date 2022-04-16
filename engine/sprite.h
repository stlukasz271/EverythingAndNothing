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
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
        string getPath(){
            return paths[anim][frame];
        }
        pair<double,double> getV(){
            return {dx,dy};
        }
        pair<double,double> getA(){
            return {ax,ay};
        }
        void setV(double dx,double dy){
            this->dx=dx;
            this->dy=dy;
        }
        void setA(double ax,double ay){
            this->ax=ax;
            this->ay=ay;
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
            dx+=ax;
            dy+=ay;
            x+=dx;
            y+=dy;
            image.loadFromFile(getPath());
            texture.loadFromImage(image);
            texture.setSmooth(true);
            sprite.setPosition(x,y);
            sprite.setTexture(texture, true);
            window.draw(sprite);
        }

};