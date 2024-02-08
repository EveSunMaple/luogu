#include <bits/stdc++.h>
#include "world.h"
using namespace std;
typedef long long ll;

namespace H
{
	ll n, c, lst;
	int qcnt;
	void main()
	{
		qcnt = lst = 0;
		scanf("%lld%lld", &n, &c);
		printf("%lld\n", Guess(n));
	}
} // namespace H

bool Query(ll x)
{
	++H::qcnt;
	if (H::qcnt > 64)
	{
		puts("The number of queries you have made exceeded the limit!");
		exit(0);
	}
	if (x < 1 || x > H::n)
	{
		puts("The number you asked is not in [1,n]!");
		exit(0);
	}
	if (!H::lst)
	{
		H::lst = x;
		return rand() & 1;
	}
	else
	{
		bool res = llabs(x - H::lst) >= H::c;
		H::lst = x;
		return res;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		H::main();
	return 0;
}