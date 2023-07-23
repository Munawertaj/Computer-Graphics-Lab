#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void Bresenham_line_draw(int x1, int y1, int x2, int y2)
{
    if (x1 > x2)
        swap(x1, x2), swap(y1, y2);

    int dx, dy, p;
    dx = x2 - x1;
    dy = abs(y2 - y1);
    p = 2 * dy - dx;

    while (x1 <= x2)
    {
        putpixel(x1, y1, WHITE);
        if (p >= 0)
        {
            y1 < y2 ? y1++ : y1--;
            p += 2 * dy - dx;
        }
        else
            p += 2 * dy;
        x1++;
    }
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100, x2 = 400, y2 = 700;
    Bresenham_line_draw(x1, y1, x2, y2);

    getch();
    return 0;
}
