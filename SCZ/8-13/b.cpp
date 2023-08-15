#include <iostream>
#include <cstring>
#include <cstdio>
#define N 10005

using namespace std;

struct shop
{
    int a, b;
} out[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &out[i].a); 
    for (int i = 1; i <= n; i++) scanf("%d", &out[i].b); 
    return 0;
}