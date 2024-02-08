#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

long long a[1000005];

int find(int l, int r, int val)
{
    int mid = 0;
    while (r > l)
    {
        mid = (l + r) >> 1;
        if (a[mid] > val) r = mid;
        else l = mid + 1;
    }
    return l;
}

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int n, q;
    unordered_map<int, bool> hash;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        hash[a[i]] = true;
    }
    a[n + 1] = 1e10 + 1;
    sort(a + 1, a + n + 2, cmp);
    // for (int i = 1; i <= n + 1; i++) printf("%lld ", a[i]);
    // printf("\n");
    // for (int i = 1; i <= 10; i++)
    //     { int l = find(1, n + 1, i); printf("FIND: %d; AIM: %d\n", i, l); }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int l = find(1, n + 1, x); // printf("FIND: %d; AIM: %d\n", x, l);
        int r = find(1, n + 1, y); // printf("FIND: %d; AIM: %d\n", y, r);
        int ans = r - l;
        if (hash[x]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}