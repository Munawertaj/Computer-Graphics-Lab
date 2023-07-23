#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void Circle()
{
    setcolor(GREEN);
    circle(100, 100, 45);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(105, 105, GREEN);
}

void Rectangle()
{
    setcolor(RED);
    rectangle(100, 100, 180, 180);
    setfillstyle(SOLID_FILL, RED);
    floodfill(101, 101, RED);
}

void Triangle()
{
    setcolor(YELLOW);
    int x[] = {10, 50, 100, 10}, y[] = {100, 20, 100, 100};
    for (int i = 0; i < 3; i++)
        line(x[i], y[i], x[i + 1], y[i + 1]);

    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(50, 50, YELLOW);
}

int main()
{
    string sequence;
    cin >> sequence;

    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    for (auto ch : sequence)
    {
        if (ch == 'C')
            Circle();
        else if (ch == 'T')
            Triangle();
        else
            Rectangle();
    }

    getch();
    return 0;
}

/*
Sample Input:
RTC or RCT or CRT or CTR or TRC or TCR
*/
