#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int box[4];
double now[4];
int light[4];
int ans = 0;

void init()
{
    for (int i = 0; i < 4; i++)
        now[i] = box[i];
    now[0] -= (double)light[0] + (double)light[1] / 2 + (double)light[2] / 2 + (double)light[3] / 4;
    now[1] -= (double)light[1] + (double)light[0] / 2 + (double)light[3] / 2 + (double)light[2] / 4;
    now[2] -= (double)light[2] + (double)light[0] / 2 + (double)light[3] / 2 + (double)light[1] / 4;
    now[3] -= (double)light[3] + (double)light[1] / 2 + (double)light[2] / 2 + (double)light[0] / 4;
}

double value(int i)
{
    double res;
    if (i = 0) res = max(now[0], (double)1) + max(now[1], (double)1 / 2) + max(now[2], (double)1 / 2) + max(now[3], (double)1 / 4);
    if (i = 1) res = max(now[1], (double)1) + max(now[0], (double)1 / 2) + max(now[3], (double)1 / 2) + max(now[2], (double)1 / 4);
    if (i = 2) res = max(now[2], (double)1) + max(now[0], (double)1 / 2) + max(now[3], (double)1 / 2) + max(now[1], (double)1 / 4);
    if (i = 3) res = max(now[3], (double)1) + max(now[1], (double)1 / 2) + max(now[2], (double)1 / 2) + max(now[0], (double)1 / 4);
    return res;
}

void solve()
{
    vector<int> temp;
    temp.push_back(0);
    int t = 0;
    for (int i = 0; i < 4; i++)
    {
        if (now[i] == now[t])
        {
            temp.push_back(i);
        }
        if (now[i] > now[t])
        {
            temp.clear();
            temp.push_back(i);
            t = i;
        }
    }
    printf("Temp:");
    vector<int> newfind;
    newfind.push_back(temp[0]);
    t = temp[0];
    for (int i = 0; i < temp.size(); i++)
    {
        printf("%d ", temp[i]);
        if (light[temp[i]] == light[t])
        {
            newfind.push_back(temp[i]);
        }
        if (light[temp[i]] < light[t])
        {
            newfind.clear();
            newfind.push_back(temp[i]);
            t = temp[i];
        }
    }
    printf("\nNewfind:");
    t = newfind[0];
    for (int i = 0; i < newfind.size(); i++)
    {
        printf("%d ", newfind[i]);
        if (value(newfind[i]) > value(t))
        {
            t = newfind[i];
        }
    }
    light[t]++;
    ans++;
    init();
    printf("\nNOW:\n");
    printf("lig: %d|%d|%d|%d\n", light[0], light[1], light[2], light[3]);
    printf("nee: %f|%f|%f|%f\n", now[0], now[1], now[2], now[3]);
}

int main()
{
    // freopen("light.in", "r", stdin);
    // freopen("light.out", "w", stdout);
    int n;
    scanf("%d%d%d%d", &box[0], &box[1], &box[2], &box[3]);
    init();
    while ((int)now[0] > 0 || (int)now[1] > 0 || (int)now[2] > 0 || (int)now[3] > 0) solve();
    printf("%d", ans);
    return 0;
}
