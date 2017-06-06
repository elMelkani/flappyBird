#include <simplecpp>
const int window_width= 800;
const int window_height= 500;
class obstruction
{
    int y1;
    int y2;
    int width;
    Rectangle upper;
    Rectangle lower;
    
    public:
    obstruction *next;
    obstruction(int y01, int y02, int w);// : upper(window_width, y01/2, w, y01 ), lower(window_width, (window_height + y02)/2, w, window_height - y02)
    void draw();
    void obstMove();
	int getObstX();
	int getObstY1();
	int getObstY2();
};

class bird
{
    int x, y, acc_factor;
    float vx, vy;
    Circle ball;
    public:
    bird();// : ball(window_width/5,window_height/2,5) 
    
    void fly();
    void jump();
	int getBirdY();
};
