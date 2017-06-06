#include "flappybird.h"
#include <stdlib.h>
using namespace std;

int random_y1(int y1)
{
	int y = (rand()%200 - 100) + y1;
	if(y<= 0 || (y+100)>=window_height) return random_y1(y1);
	else return y;
}
main_program
{
   bool game_over = false;
   initCanvas("Flappy bird", window_width, window_height);
   getClick();
   int y1 = (window_height - 100)/2;
   int y2 = (window_height + 100)/2;
   double timer = 0;
   obstruction *o1;
   obstruction *front, *rear, *current; //deletion at front
   o1 = new obstruction(y1, y2, 100);
   front = rear = current = o1;
   bird b;
   while(!game_over)
        {
            XEvent event;
            b.fly();
            o1 = front;
            while(true)                            //code for moving obstructions
            {
				o1->obstMove();
				if(!o1->next) break;
				else o1 = o1->next;				
			}
			if((window_width - rear->getObstX() )>= 300)   // code for making new obstructions
			{
				y1 = random_y1(y1);
				y2 = y1 + 100;
				o1 = new obstruction(y1, y2, 100);
				rear-> next = o1;
				rear = o1;
			}
			if(front->getObstX() <= 0)   // code for deleting obstructions that go out of screen
			{
				o1 = front;
				front = front->next;
				delete o1;
			}
			if((b.getBirdY() > current->getObstY2()  || b.getBirdY() < current->getObstY1()) && ((current->getObstX()-50) < window_width/5 && (current->getObstX()+50) > window_width/5 ) ) game_over = true;
			if((current->getObstX()+50)<window_width/5) current = current->next;//update current
            if(checkEvent(event) && mouseButtonPressEvent(event)) b.jump();    //if user clicks
            if(checkEvent(event) && keyPressEvent(event)) game_over = true;
            if(b.getBirdY() >= window_height) game_over = true;                //bird goes below screen
            wait(0.01);
            timer+=0.01;
        }
        while(true)                            //flush all obstructions
        {
			o1 = front;
			if(!o1->next) break;
			front = front->next;
			delete o1;					
		}
   delete o1; delete front; delete rear; delete current;
   cout<<" your score is"<< timer;
}
