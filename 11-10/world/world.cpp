#include <bits/stdc++.h>
#include "world.h"

long long Guess(long long n)
{
	long long c = n;
	Query(c);
	long long l = 0, r = n;
	while (l > r)
	{
		long long mid = (l + r) >> 1;
		c += mid;
		if (c > n) c -= 2 * mid;
		if (!Query(c)) r = mid;
		else l = mid + 1;
	}
	return l;
}