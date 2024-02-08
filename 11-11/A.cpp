#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define N 600005
#define LL long long

using namespace std;

struct line
{
    int ver;
    int nxt;
    LL len;
    line()
    {
        ver = 0;
        nxt = 0;
        len = 0;
    }
    line(int a, int b, LL c)
    {
        ver = a;
        nxt = b;
        len = c;
    }
} edge[N * 2];

struct cmp
{
    bool operator()(line a, line b)
    {
        return a.len > b.len;
    }
};

int head[N];
int node[N];
int tot = 0;
LL now = 0;

priority_queue<line, vector<line>, cmp> solve;

void add(int u, int v, LL w)
{
    edge[++tot].nxt = head[u];
    edge[tot].ver = v;
    edge[tot].len = w;
    head[u] = tot;
}

int main()
{
	// freopen("A.in", "r", stdin);
	// freopen("A.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        LL w;
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= k; i++)
    {
        int l;
        LL t;
        scanf("%d%d", &l, &t);
        solve.push(line(l, head[l], t));
    }
    while (!solve.empty())
    {
        now += solve.top().len;
        while (true)
        {
            line temp = solve.top();
            if (temp.len <= now)
            {
                solve.pop();
                if (node[temp.ver] != 0) break;
                else node[temp.ver] = temp.len;
                for (int i = head[temp.ver]; i; i = edge[i].nxt)
                {
                    if (node[edge[i].ver] != 0) continue;
                    solve.push(line(edge[i].ver, edge[i].nxt, temp.len + edge[i].len));
                }
            }
            else
                break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", node[i]);
    }
    return 0;
}
