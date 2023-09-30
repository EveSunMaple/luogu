#include <iostream>
#include <cstring>
#include <cstdio>
#define ll unsigned long long
#define N 1000006
 
using namespace std;
 
ll f[100];
ll g[100];
ll n, p, r;
 
struct _in
{
    ll cnt;
    ll val;
} num[N];
 
ll pow(ll a)
{
    ll ans = 1;
    for (ll i = 0; a; i++)
    {
        if (a & 1)
        {
            ans = (ans * f[i] % p) % p;
        }
        a >>= 1;
    }
    return ans;
}
 
ll get(ll a)
{
    ll ans = 0;
    for (ll i = 0; a; i++)
    {
        if (a & 1)
        {
            ans = (ans + (g[i] * pow(a - 1)) % p) % p;
        }
        a >>= 1;
    }
    return ans;
}
 
int main()
{  
    scanf("%llu%llu%llu", &n, &p, &r);
    f[0] = r; g[0] = 1;
    for (ll i = 1; i <= 64; i++)
    {
        f[i] = (f[i - 1] * f[i - 1]) % p;
        g[i] = (g[i - 1] + (g[i - 1] * f[i - 1]) % p) % p; 
    }
    for (ll i = 1; i <= n; i++)
    {
        scanf("%llu%llu", &num[i].cnt, &num[i].val);
    }
    ll ans = 0;
    ll res = 1;
    for (ll i = n; i >= 1; i--)
    {
        ll tmp = (num[i].val * res) % p;
        ans = (ans + (get(num[i].cnt) * tmp) % p) % p;
        res = (res * pow(num[i].cnt)) % p;
    }
    printf("%llu", ans);
    return 0;
}
