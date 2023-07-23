#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void Midpoint_Circle_Draw(int r, int Xc, int Yc)
{
    int x, y, p;
    x = 0;
    y = r;
    p = 1 - r;

    putpixel(Xc, Yc, WHITE);

    vector<pair<int, int>> points;

    while (x <= y)
    {
        points.push_back({x, y});
        points.push_back({y, x});

        x++;

        if (p >= 0)
            p += 2 * (x - y) + 1, y--;
        else
            p += 2 * x + 1;
    }

    for (auto p : points)
    {
        x = p.first;
        y = p.second;
        putpixel(Xc + x, Yc + y, WHITE);
        putpixel(Xc - x, Yc + y, WHITE);
        putpixel(Xc + x, Yc - y, WHITE);
        putpixel(Xc - x, Yc - y, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    int radius = 200, Xc = 250, Yc = 250;
    Midpoint_Circle_Draw(radius, Xc, Yc);

    getch();
    return 0;
}
