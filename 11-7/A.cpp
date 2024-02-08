#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 400005

using namespace std;

struct node
{
    int l, r;
    int tag = true;
};

vector<node> g[N];

bool cmp(node a, node b)
{
    if (a.r > b.r)
        return true;
    return false;
}

node init(int x, int y)
{
    node temp;
    temp.l = x;
    temp.r = y;
    return temp;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.OUT", "w", stdout);
    int ans = 0;
    int n, MAX = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(init(x, y));
        MAX = max(x, MAX);
    }
    for (int i = 1; i <= MAX; i++)
        sort(g[i].begin(), g[i].end(), cmp);
    for (int i = 1; i <= MAX; i++)
    {
        for (int t1 = g[i].size() - 1; t1 >= 0; t1--)
        // for (node temp : g[i])
        {
            if (g[i][t1].tag)
                for (int j = g[i][t1].r + 1; j <= MAX; j++)
                {
       				for (int t2 = 0; t2 < g[j].size(); t2++)
        	        // for (node comp : g[j])
                    {
                        if (g[j][t2].tag)
                        {
                            g[i][t1].tag = false;
                            g[j][t2].tag = false;
                            //printf("Find a couple : [%d, %d] & [%d, %d]\n", g[i][t1].l, g[i][t1].r, g[j][t2].l, g[j][t2].r);
                            ans++;
                            goto end;
                        }
                    }
                }
        end:
            continue;
        }
    }
    printf("%d\n", ans);
    return 0;
}
