#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define N 100010

using namespace std;

int n, m;
int head[N], edge[N << 1], nxt[N << 1], tot;
int f[N][15];

void add(int a, int b)
{
    edge[tot] = b;
    nxt[tot] = head[a];
    head[a] = tot++;
}

void dfs(int u, int father)
{
    for (int i = head[u]; ~i; i = nxt[i])
    {
        int j = edge[i];
        if (j == father)
            continue;
        dfs(j, u);
        for (int k = m; k >= 0; k --)
            for (int t = 0; t <= k; t ++)
                f[u][k] = max(f[u][k], f[u][k - t] + f[j][t] + (t > 0));
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, -1);
    printf("%d\n", f[1][m]);
    return 0;
}