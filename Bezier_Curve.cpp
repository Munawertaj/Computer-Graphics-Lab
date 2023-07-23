#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

vector<pair<int, int>> points;

int nCr(int n, int r)
{
    int ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

double power(double b, int p)
{
    double ans = 1;
    while (p--)
        ans *= b;

    return ans;
}

double Bazier_Function(int n, int k, double u)
{
    return nCr(n, k) * power(u, k) * power((1 - u), (n - k));
}

void Draw_Points()
{
    for (auto p : points)
    {
        putpixel(p.first, p.second, WHITE);
        circle(p.first, p.second, 5);
        delay(500);
    }
}

void Draw_Bezier_Curve()
{
    int n = points.size() - 1;
    double eps = 0.00005;

    for (double u = 0; u <= 1; u += eps)
    {
        double x = 0, y = 0;
        for (int i = 0; i <= n; i++)
        {
            double bez = Bazier_Function(n, i, u);
            x += points[i].first * bez;
            y += points[i].second * bez;
        }
        putpixel(x, y, WHITE);
    }
}

int main()
{
    int num_of_points;
    cin >> num_of_points;
    int x, y;
    for (int i = 0; i < num_of_points; i++)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }

    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    Draw_Points();
    Draw_Bezier_Curve();

    getch();
    return 0;
}

/*
Sample input:
4
25 250
100 50
250 200
400 25
*/
