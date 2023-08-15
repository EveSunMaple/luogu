#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 100005

using namespace std;

/*struct node
{
	int ver;
	int nxt;
}edge[N * 2];

int head[N * 2];
int deg[N];
int n, ans;
int tot;

void add(int u, int v)
{
	tot++;
	edge[tot].ver = v;
	edge[tot].nxt = head[u];
	head[u] = tot;
}*/
struct simple
{
	int l;
	int r;
}node[N];

int n, m;
int tot;

bool com(simple a, simple b)
{
	return a.r < b.r;
}

int main()
{
	freopen("simple.in", "r", stdin);
	freopen("simple.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (abs(u - v) > 1)
		{
			tot++;
			node[tot].l = min(u, v);
			node[tot].r = max(u, v);
		}
		/*add(u, v); add(v, u);
		deg[u]++; deg[v]++;*/
	}
	
	sort(node + 1, node + tot + 1, com);
	
	int r = 0, ans = n - 1;
	for(int i = 1; i <= tot; i++)
	{
		if (node[i].l >= r)
		{
			r = node[i].r;
			ans++;
		}
	}
	
	printf("%d", ans);
	
	return 0;	
} 
