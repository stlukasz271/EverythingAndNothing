using namespace std;

class Vector{
    private:
        double x=0.0,y=0.0;
    public:
        Vector(double x, double y){
            this->x=x;
            this->y=y;
        }
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
        double sqlen(){
            return x*x+y*y;
        }
        double len(){
            return sqrt(sqlen());
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
        void add(double x, double y){
            addX(x);
            addY(y);
        }
        void multX(double x){
            setX(this->x*x);
        }
        void multY(double y){
            setY(this->y*y);
        }
        void mult(double x, double y){
            multX(x);
            multY(y);
        }
        void mult(double k){
            multX(k);
            multY(k);
        }
        void add(Vector other){
            add(other.x,other.y);
        }
        void dot(Vector other){
            mult(other.getX(),other.getY());
        }
        void cross(Vector other){
            mult(other.getY(),other.getX());
        }
};

Vector add(Vector a, Vector b){
    Vector c(a.getX(),a.getY());
    c.add(b);
    return c;
}

Vector dotProduct(Vector a, Vector b){
    Vector c(a.getX(),a.getY());
    c.mult(b.getX(),b.getY());
}

Vector crossProduct(Vector a, Vector b){
    Vector c(a.getX(),a.getY());
    c.mult(b.getY(),b.getX());
}
