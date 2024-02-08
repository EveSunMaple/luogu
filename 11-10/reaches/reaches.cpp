#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

struct couple
{
    long long x, y, dist;
};

bool tag[201];
vector<couple> g;
couple point[201];
couple a, b, p;
long long x, y, t;
namespace nor
{
    // int solve()
    // {
    //     for (int i = 1; i <= 100; i++)
    //     {
    //         // printf("[%lld, %lld] = %lld\n", point[i].x, point[i].y, abs(point[i].x) + abs(point[i].y));
    //         // point[i + 1].x = a.x * point[i].x + b.x;
    //         // point[i + 1].y = a.y * point[i].y + b.y;
    //         // point[i].dist = abs(point[i].x - x) + abs(point[i].y - y);
    //         // if (point[i].dist > t)
    //         // {
    //         //     if ()
    //         //     return i / 2;
    //         // }
    //         // printf("GOTO => %lld\n", abs(point[i].x - point[i + 1].x) + abs(point[i].y+ point[i + 1].y));
    //     }
    // }
}

int nor_find(couple now, long long val, int res, int times)
{
    for (int i = 0; i < g.size(); i++)
    {
        if (!tag[i])
        {
            tag[i] = true;
            long long r = abs(g[i].x - now.x) + abs(g[i].y - now.y);
            // for (int j = 1; j <= times; j++)
            //     printf("|   ");
            // printf("[%lld, %lld]", g[i].x, g[i].y);
            // printf("\n");
            res = max(res, 1 + nor_find(g[i], val - r, 0, times + 1));
            tag[i] = false;
        }
    }
    return res;
}

int main()
{
    //freopen("reaches.in", "r", stdin);
    //freopen("reaches.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld%lld", &x, &y, &a.x, &a.y, &b.x, &b.y);
    scanf("%lld%lld%lld", &p.x, &p.y, &t);
    point[1].x = x;
    point[1].y = y;
    for (int i = 1; i <= 100; i++)
    {
        point[i + 1].x = a.x * point[i].x + b.x;
        point[i + 1].y = a.y * point[i].y + b.y;
        point[i].dist = abs(point[i].x - p.x) + abs(point[i].y - p.y);
        if (abs(point[i].x - p.x) > t || abs(point[i].y - p.y) > t) break;
        if (point[i].dist <= t)
        {
            g.push_back(point[i]);
            // printf("[%lld, %lld] = %lld\n", point[i].x, point[i].y, point[i].dist);
        }
    }
    printf("%d", nor_find(p, t, 0, 0));
    return 0;
}