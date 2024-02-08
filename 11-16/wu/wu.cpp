#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int map[2005][2005];
int sum[2005][2005];
int n, m, ans = 0;

bool check_0(int x1, int y1, int x2, int y2, int t)
{
	int res = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
	return res == t * t;
}

bool check_1(int x1, int y1, int x2, int y2)
{
	int res = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
	return res == (x2 - x1 + 1) * (y2 - y1 + 1);
}

int find(int x, int y, int t)
{
	// THIS IS NOOB WAY :(
	
	// int right = 1;
	// int down = 1;
	// for (; right <= m - x && check_0(x + 1, y - t + 1, x + right, y); right++);
	// for (; down <= n - y && check_0(x - t + 1, y + 1, x, y + down); down++);
	// right--; down--;
	// printf("range [%d -> %d<%d>, %d -> %d<%d>] --- {size: %d}\n", x, x + right, right, y, y + down, down, t);
	// return right + down - 1;
	
	// LASTEST SOLUTION EX ONLY 0.1441s :)
	// =========================
	int right = 1;
	int down = 1;
	int temp = 0;
	int res = 0;
	// First: Find the DOWN(int)
	for (; down + y <= n && check_0(x - t + 1, y - t + 1, x + 1, y + down, t); down++);
	down--;
	// Second: Find the right
	for (; right + x <= m && down >= 1;)
	{
		if (check_0(x - t + 1, y - t + 1, x + right, y + down, t)) right++;
		else
		{
			right--;
			res += down * (right - temp);
			temp = right;
			down--;
		}
	}
	if (!check_0(x - t + 1, y - t + 1, x + right, y + down, t)) right--;
	res += down * (right - temp);
	return res;
}

int main()
{
	// freopen("wu.in", "r", stdin);
	// freopen("wu.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &map[j][i]);
			sum[j][i] = map[j][i] + sum[j - 1][i] + sum[j][i - 1] - sum[j - 1][i - 1];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (map[j][i] == 0) continue;
			if (map[j][i + 1] == 1 || map[j + 1][i] == 1)  continue;
			for (int t = 1; j - t >= 0 && i - t >= 0; t++)
			{
				if (check_1(j - t + 1, i - t + 1, j, i)) ans += find(j, i, t);
				else break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
