#include "flappybird.h"
#include <simplecpp>

    obstruction::obstruction(int y01, int y02, int w) : upper(window_width, y01/2, w, y01 ), lower(window_width, (window_height + y02)/2, w, window_height - y02)
    {
        width = w;
        y1 = y01;
        y2 = y02;
        next = nullptr;
        draw();
    }
    void obstruction::draw()
    {
        upper.setFill(true);
		upper.setColor(COLOR("RED"));
		upper.imprint();
		lower.setFill(true);
		lower.setColor(COLOR("RED"));
		lower.imprint();
    }
    void obstruction::obstMove()
    {
		upper.move(-2,0);    lower.move(-2,0);	
	}
	int obstruction::getObstX()   {     return (lower.getX());    }
	int obstruction::getObstY1()   {     return y1;    }
	int obstruction::getObstY2()   {     return y2;    }


    bird::bird() : ball(window_width/5,window_height/2,5) 
    {
        x = window_width/5;
        y = window_height/2;
        vy = 10;
        acc_factor = 0;
    }
    
    void bird::fly()
    {
        //ball.move(1 , (vy*1.0)/20 + ((acc_factor++)*1.0)/10);
        ball.move(0, (vy*1.0)/20 + ((acc_factor++)*1.0)/10);
    }
    void bird::jump()
    {
		vy = - 60;
        acc_factor=0;
	}
	int bird::getBirdY()   {    return (ball.getY());    }

