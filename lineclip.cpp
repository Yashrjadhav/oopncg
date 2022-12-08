/*// C++ program to implement Cohen Sutherland algorithm
// for line clipping.
#include <iostream>
using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1; // 0001
const int RIGHT = 2; // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8; // 1000

// Defining x_max, y_max and x_min, y_min for
// clipping rectangle. Since diagonal points are
// enough to define a rectangle
const int x_max = 10;
const int y_max = 8;
const int x_min = 4;
const int y_min = 4;

// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{
	// initialized as being inside
	int code = INSIDE;

	if (x < x_min) // to the left of rectangle
		code = LEFT;
	else if (x > x_max) // to the right of rectangle
		code = RIGHT;
	if (y < y_min) // below the rectangle
		code = BOTTOM;
	else if (y > y_max) // above the rectangle
		code = TOP;

	return code;
}

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
void cohenSutherlandClip(double x1, double y1,
						double x2, double y2)
{
	// Compute region codes for P1, P2
	int code1 = computeCode(x1, y1);
	int code2 = computeCode(x2, y2);

	// Initialize line as outside the rectangular window
	bool accept = false;

	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
			// If both endpoints lie within rectangle
			accept = true;
			break;
		}
		else if (code1 & code2) {
			// If both endpoints are outside rectangle,
			// in same region
			break;
		}
		else {
			// Some segment of line lies within the
			// rectangle
			int code_out;
			double x, y;

			// At least one endpoint is outside the
			// rectangle, pick it.
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			// Find intersection point;
			// using formulas y = y1 + slope * (x - x1),
			// x = x1 + (1 / slope) * (y - y1)
			if (code_out & TOP) {
				// point is above the clip rectangle
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				// point is below the rectangle
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code_out & RIGHT) {
				// point is to the right of rectangle
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else if (code_out & LEFT) {
				// point is to the left of rectangle
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			// Now intersection point x, y is found
			// We replace point outside rectangle
			// by intersection point
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = computeCode(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = computeCode(x2, y2);
			}
		}
	}
	if (accept) {
		cout << "Line accepted from " << x1 << ", "
			<< y1 << " to " << x2 << ", " << y2 << endl;
		// Here the user can add code to display the rectangle
		// along with the accepted (portion of) lines
	}
	else
		cout << "Line rejected" << endl;
}

// Driver code
int main()
{
	// First Line segment
	// P11 = (5, 5), P12 = (7, 7)
	cohenSutherlandClip(5, 5, 7, 7);

	// Second Line segment
	// P21 = (7, 9), P22 = (11, 4)
	cohenSutherlandClip(7, 9, 11, 4);

	// Third Line segment
	// P31 = (1, 5), P32 = (4, 1)
	cohenSutherlandClip(1, 5, 4, 1);

	return 0;
}

*/
#include<iostream>
#include<graphics.h>

using namespace std;

static int LEFT = 1, RIGHT= 2, BOTTOM = 4, TOP = 8,xmin, ymin, xmax, ymax;
int gc(int x, int y)
{
    int code=0;
    if(y>ymax) code|=TOP;
    if(y<ymin) code|=BOTTOM;
    if(x<xmin) code|=LEFT;
    if(x>xmax) code|=RIGHT;
    return code;
}

int main(){

    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    setcolor(WHITE);
    cout<<"Enter windows minimum and maximum value ";
    cin>>xmin>>ymin>>xmax>>ymax;
    rectangle(xmin,ymin,xmax,ymax);
    int x1,y1,x2,y2;
    cout<<"Enter the endpoints of the line";
    cin>>x1>>y1>>x2>>y2;
    line(x1,y1,x2,y2);
    int o1=gc(x1,y1),o2=(x2,y2);
    int accept=0;
    while(1){
         float m = (float)(y2-y1)/(x2-x1);
         if (o1==0 && o2==0){
                accept=1;
                break;
         }
        else if((o1 & o2)!=0)
        {
            break;

        }
        else
        {
            int x,y;
            int temp;
            if(o1==0)
                temp=o1;
            else
            temp = o2;
            if(temp & TOP)
            {
                x=x1+(ymax-y1)/m;
                y=ymax;
                }
            if(temp & BOTTOM)
            {
                x=x1+(ymin-y1)/m;
                y=ymin;
                }
            if(temp & LEFT)
            {
                x=xmin;
                y=y1+m*(xmin-x1);
                }
            if(temp & RIGHT)
            {
                x=xmax;
                y=y1+m*(xmax-x1);
                }
            if(temp == o1)
            {
                x1=x;
                y1=y;
                o1=gc(x1,y1);
                }
            if(temp == o2)
            {
                x2=x;
                y2=y;
                o2=gc(x2,y2);
                }
            }

        }

        cout<<"after clipping";
        if(accept)
            cleardevice();
            rectangle(xmin,ymin,xmax,ymax);
            setcolor(RED);
            line(x1,y1,x2,y2);
        closegraph;
        delay(10000);
        return 0;

}

// Input :

//100 100 500 500
//100 200 500 100
