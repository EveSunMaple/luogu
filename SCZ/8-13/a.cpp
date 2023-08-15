#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100005

using namespace std;

struct node
{
    int ver, nxt, w;
} edge[N];
bool tag[N];
bool ins[N];
int head[N];
int tot = 0;
int ans = 0;

void add(int u, int v, int w)
{
    tot++;
    edge[tot].w = w;
    edge[tot].ver = v;
    edge[tot].nxt = head[u];
    head[u] = tot;
}

// 暴力算法验证正确性
bool dfs(int u, int dp, int aim, int l)
{
    bool res = false;
    if (u == aim && dp <= l) return true;
    for (int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].ver;
        if (ins[v]) continue;
        ins[v] = true;
        int w = edge[i].w;
        bool tmp = dfs(v, dp + w, aim, l);
        if (tmp && !tag[i])
        {
            tag[i] = true;
            ans++;
        }
        res |= tmp;
        ins[v] = false;
    }
    return res;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        memset(ins, false, sizeof(ins));
        dfs(u, 0, v, l);
    }
    printf("%d", ans);
    return 0;
}