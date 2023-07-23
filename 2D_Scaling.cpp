#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

int num_of_vertex;
int x[10], y[10];
int sfx, sfy;

void draw_polygon()
{
    x[num_of_vertex] = x[0];
    y[num_of_vertex] = y[0];

    for (int i = 0; i < num_of_vertex; i++)
        line(x[i], y[i], x[i + 1], y[i + 1]);
}

void scaling()
{
    for (int i = 0; i < num_of_vertex; i++)
        x[i] *= sfx, y[i] *= sfy;
}

int main()
{
    cin >> num_of_vertex;
    for (int i = 0; i < num_of_vertex; i++)
        cin >> x[i] >> y[i];

    cin >> sfx >> sfy;

    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    setcolor(YELLOW);
    draw_polygon();
    scaling();
    setcolor(WHITE);
    draw_polygon();

    getch();
    return 0;
}

/*
Sample input:
3
100 100
100 200
200 100
2 2

*/
