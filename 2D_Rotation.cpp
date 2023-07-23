#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

#define pi acos(-1.0)
// Convert degree into Radian
#define Sin(x) sin(x *(pi / 180))
#define Cos(x) cos(x *(pi / 180))

int num_of_vertex;
int x[10], y[10];
int angle;
int xPivot, yPivot;

void draw_polygon()
{
    x[num_of_vertex] = x[0];
    y[num_of_vertex] = y[0];

    for (int i = 0; i < num_of_vertex; i++)
        line(x[i], y[i], x[i + 1], y[i + 1]);
}

void rotation()
{

    for (int i = 0; i < num_of_vertex; i++)
    {
        int xShift = x[i] - xPivot, yShift = y[i] - yPivot;
        x[i] = xPivot + (xShift * Cos(angle) - yShift * Sin(angle));
        y[i] = yPivot + (xShift * Sin(angle) + yShift * Cos(angle));
    }
}

int main()
{
    cin >> num_of_vertex;

    for (int i = 0; i < num_of_vertex; i++)
        cin >> x[i] >> y[i];

    cin >> angle; // Enter angle in degree
    cin >> xPivot >> yPivot;

    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    setcolor(YELLOW);
    draw_polygon();
    rotation();
    setcolor(WHITE);
    draw_polygon();

    getch();
    return 0;
}

/*
Sample Input:
4
100 100
100 200
200 200
200 100
45
200 200

*/
