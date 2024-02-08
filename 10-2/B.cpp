#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
struct node
{
    int ty, val;
} a[N];
bool cmp(node a, node b) { return a.val < b.val; }
int main()
{
    int n, m, x = 0, y = 0;
    long long sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].val), a[i].ty = 1;
    for (int i = n + 1; i <= n + m; i++)
        scanf("%d", &a[i].val), a[i].ty = 2;
    sort(a + 1, a + n + m + 1, cmp);
    for (int i = 1; i <= n + m; i++)
    {
        if (a[i].ty == 1)
        {
            sum += 1ll * (m - 1) * a[i].val;
            x = x < n ? x + 1 : x;
            if (x > 1 && y > 1)
                sum -= 1ll * (y - 1) * a[i].val;
        }
        else
        {
            sum += 1ll * (n - 1) * a[i].val;
            y = y < m ? y + 1 : y;
            if (x > 1 && y > 1)
                sum -= 1ll * (x - 1) * a[i].val;
        }
    }
    cout << sum << endl;
    return 0;
}