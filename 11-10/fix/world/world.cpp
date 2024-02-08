#include <bits/stdc++.h>
#include "world.h"

long long Guess(long long n)
{
	long long c = n / 3 + 1;
	Query(c);
	long long l = 0, r = n;
	while (l < r)
	{
		long long mid = (l + r) >> 1;
		c += mid;
		if (c > n)
			c -= 2 * mid;
		if (c <= 0)
		{
			c = 1;
			Query(c);
			c += mid;
		}
		if (Query(c))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}