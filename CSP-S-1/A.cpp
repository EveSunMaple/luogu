#include <iostream>
#include <cstring>
#include <cstdio>
#define mod 993244853
#define MAXN 505

using namespace std;

char map[MAXN][MAXN];

int search(int lx, int ly, int rx, int ry)
{
    int sum = 0;
    printf("Now : %c (%d, %d) | %c (%d, %d)\n", map[lx][ly], lx, ly, map[rx][ry], rx, ry);
    if ((rx - lx == ry - ly) && rx - lx == 1) return 2;
    if (rx - lx <= 1 && ry - ly <= 1) return 1;
    if (map[lx + 1][ly] == map[rx - 1][ry]) sum = (sum + search(lx + 1, ly, rx - 1, ry)) % mod;
    if (map[lx][ly + 1] == map[rx - 1][ry]) sum = (sum + search(lx, ly + 1, rx - 1, ry)) % mod;
    if (map[lx + 1][ly] == map[rx][ry - 1]) sum = (sum + search(lx + 1, ly, rx, ry - 1)) % mod;
    if (map[lx][ly + 1] == map[rx][ry - 1]) sum = (sum + search(lx, ly + 1, rx, ry - 1)) % mod;
    return sum;
}

int main()
{
    int w, h;
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= w; j++)
        {
            map[j][i] = tmp[j - 1];
        }
    }
    int l = w + h - 1;
    scanf("%d", search(1, 1, w, h));
    return 0;
}