#include <iostream>
#include <cstring>
#include <cstdio>
#define LL long long 

using namespace std;

LL nor(LL n, LL m)
{
    LL res = 1;
    for (LL i = 1; i <= m; ++i)
    {
        res = res * (n - m + i) / i;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    if (k == 1)
    {
        int ans = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == '0') ans++;
        }
        printf("%d", ans);
    }
    else
    {
        printf("%lld", nor(n, k));
    }
    return 0;
}