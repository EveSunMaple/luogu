#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a[1000000];
int ans = 0;

int main()
{
    int t, l = 0;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &a[i]);
        l += a[i];
    }
    l /= 3;
    for (int i = 1; i <= t; i++)
    {
        int temp = 0;
        for (int j = i; j <= t + i; j++)
        {
            temp += a[j];
            if (temp > l) break;
            ans = max(ans, temp);
        }
    }
    printf("%d", ans);
    return 0;
}