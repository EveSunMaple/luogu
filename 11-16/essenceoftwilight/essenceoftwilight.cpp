#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100005

using namespace std;

namespace noob
{
	int n;
	long long a[N];
	long long tmp[N];
	long long solve()
	{
		long long res = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (tmp[i] > tmp[j]) res++;
			}
		}
		return res;
	}
	void main()
	{
		long long ans = 1e9;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int t = 1; t <= n; t++)
				{
					tmp[t] = a[t];
				}
				tmp[i] = a[j];
				tmp[j] = a[i];
				ans = min(ans, solve());
			}
		}
		printf("%lld\n", ans);
	}
}

int main()
{
	freopen("essenceoftwilight.in", "r", stdin);
	freopen("essenceoftwilight.out", "w", stdout);
	int T, o;
	scanf("%d%d", &T, &o);
	while (T--)
	{
		noob::main();
	}
	return 0;
}
