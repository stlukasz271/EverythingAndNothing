
using namespace std;

int GAME_W = 640;
int GAME_H = 480;
double G_ACC = 0.0;//0.981;
double EPS = 0.01;
string TITLE = "Bababooey";
string ASSETPATH =  "assets\\";

int randint(int a, int b){
    int range = b - a + 1;
    int num = rand() % range + a;
}