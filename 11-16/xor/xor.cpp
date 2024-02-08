#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100005

using namespace std;

long long a[N], A[N], M[N];
int n, m;

namespace noob
{
	void change(int t)
	{
		for (int i = 1; i <= n; i++) a[i] = A[i] ^ M[t];
	}
	long long solve()
	{
		long long res = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (a[i] > a[j]) res++;
			}
		}
		return res;
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &M[i]);
	for (int i = 1; i <= m; i++)
	{
		noob::change(i); 
		printf("%lld\n", noob::solve());
	}
	return 0;
}
