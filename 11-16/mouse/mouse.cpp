#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a[100][2];
int n, k;
int MAX, ans = 0;

int mul(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
		{
			res *= a;
		}
		a *= a;
		b >>= 1;
	}
	return res;
}

void print()
{
	printf("NOW:\n");
	for (int i = 1; i <= n; i++) printf("%d ", a[i][0]); printf("\n");
	for (int i = 1; i <= n; i++) printf("%d ", a[i][1]); printf("\n");
}

namespace noob
{
	bool cmp(int x, int y)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == x || a[i][y] == -1) continue;
			if (a[i][y] == a[x][y]) return false;
		}
		if (a[x][y ^ 1] != -1 && a[x][y ^ 1] == a[x][y]) return false;
		return true;
	}
	bool check()
	{
		int res = 0;
		for (int i = 1; i <= n; i++) res = res ^ a[i][0] ^ a[i][1];
		return res == 0;
	}
	void solve(int x, int y)
	{
		for (int i = 0; i < MAX; i++)
		{
			a[x][y] = i;
			if (cmp(x, y))
			{
				if (x == n)
				{
					if (y == 1)
					{
						if (check()) ans++;
					}
					else solve(1, 1);
				}
				else solve(x + 1, y);
			}
		}
		a[x][y] = -1;
		return;
	}
}

int main()
{
	freopen("mouse.in", "r", stdin);
	freopen("mouse.out", "w", stdout); 
	scanf("%d%d", &n, &k);
	MAX = mul(2, k);
	memset(a, -1, sizeof a);
	noob::solve(1, 0);
	printf("%d", ans);
	return 0;
}
