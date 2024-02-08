#include <iostream>
#include <cstring>
#include <cstdio>
#define mod 1000000007

using namespace std;

int mul(int a, int b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void choice(int n)
{
    for ()
}

int a[100];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {   
        scanf("%d", &a[i]);
    }
    
    return 0;
}