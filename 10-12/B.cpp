#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100005

using namespace std;

int a[N];
int fa[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 2; i <= n; i++) scanf("%d", &fa[i]);
    
    return 0;
}