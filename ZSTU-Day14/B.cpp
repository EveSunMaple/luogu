#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005
#define mod 998244353

using namespace std;

struct Node
{
    int ver, nxt, val;
} edge[N * 2];

int head[N];
int node[N];
int vis[N];
int tot;
int ans;

void add(int u, int v, int w)
{
    tot++;
    edge[tot].ver = v;
    edge[tot].val = w;
    edge[tot].nxt = head[u];
    head[u] = tot;
}

void dfs(int u, int from, int e_s, int n_s)
{
    e_s %= mod;
    n_s %= mod;
	// printf("NOW IN : %d\n", u);
	// printf("ADD : %d * %d\n", e_s, n_s);
    if (!vis[u]) ans = (ans + (e_s * n_s) % mod * 2 % mod) % mod;
    for (int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].ver;
        if (v == from) continue; 
        dfs(v, u, e_s + edge[i].val, n_s + node[v]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &node[i]);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    for (int i = 1; i <= n; i++)
    {
        vis[i] = true;
		// printf("FROM : %d\n", i);
        dfs(i, 0, 0, node[i]);
    }
    printf("%d", ans);
    return 0;
}
