#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>


using namespace std;
void drawCircle(int x1, int y1, int x, int y)
{
    putpixel(x1+x, y1+y,WHITE);
    putpixel(x1-x, y1+y, WHITE);
    putpixel(x1+x, y1-y, WHITE);
    putpixel(x1-x, y1-y, WHITE);
    putpixel(x1+y, y1+x, WHITE);
    putpixel(x1-y, y1+x, WHITE);
    putpixel(x1+y, y1-x, WHITE);
    putpixel(x1-y, y1-x, WHITE);
}

void circleBres(int x1, int y1, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(x1, y1, x, y);
    while (y >= x)
    {

        x++;

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(x1, y1, x, y);
        delay(50);
    }
}


void DDALine(int x0, int y0, int x1, int y1)
{


	int dx = x1 - x0;
	int dy = y1 - y0;

	int step;


	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);


	float x_incr = (float)dx / step;
	float y_incr = (float)dy / step;


	float x = x0;
	float y = y0;

	for (int i = 0; i < step; i++) {

		 putpixel(round(x), round(y), WHITE);
		cout << round(x) << " " << round(y) << "\n";
		x += x_incr;
		y += y_incr;
        delay(0.1);
	}
}

// Driver code

// all functions regarding to graphichs.h are commented out
// contributed by hopelessalexander


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    DDALine(200,20,300,70);
    DDALine(100,20,300,20);
    DDALine(300,20,300,120);
    DDALine(100,120,300,120);
    DDALine(100,120,100,20);
    DDALine(200,20,100,70);
    DDALine(100,70,200,120);
    DDALine(200,120,300,70);
    circleBres(200,70,45);
    delay(500000000);
    closegraph();
    return 0;
}


