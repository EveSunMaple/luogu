#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1000005
#define ll long long
#define i128 __int128

using namespace std;

struct _in
{
    ll cnt, val;
} num[N];
i128 len;
ll n, p, r;

ll pow(ll a, i128 b)
{
    ll ans = 1;
    ll res = a % p;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * res) % p;
        }
        res = (res * res) % p;
		b /= 2;
    }
	return ans;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) 
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll z = x; x = y; y = z - (a / b) * y;
    return d;
}

int main()
{
    scanf("%lld%lld%lld", &n, &p, &r);
    for (ll i = 1; i <= n; i++)
    {
        ll c, a;
        scanf("%lld%lld", &c, &a);
        len += c;
        num[i].cnt = c;
        num[i].val = a;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        len -= num[i].cnt;
        ll temp = pow(r, len);
		// printf("FIRST : %lld\n", temp);
        // need (r - 1)^{-1}
        ll res = 1, k = 0;
        ll d = exgcd(r - 1, p, res, k);
        res /= d;
        res = (res % p + p) % p;
        ll sum = ((pow(r, num[i].cnt) - 1) * res) % p;
		// printf("SECOND : %lld\n", sum);
        ans = (ans + ((temp * sum) % p * num[i].val) % p) % p;
    }
    printf("%lld", ans);
    return 0;// a(1-q^n)/(1-q)
}