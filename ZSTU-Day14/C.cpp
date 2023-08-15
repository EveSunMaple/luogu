#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1048580
#define ls (x << 1)
#define rs (ls | 1)

using namespace std;

struct Node
{
    int l, r, sum;
    int add, cor;
} tree[N * 4];
int n, m, W;
int sum[N];
int res[N]; // 差分
int a[N];
int b[N];

void pushup(int x)
{
    tree[x].sum = tree[ls].sum + tree[rs].sum;
}

void down(int x)
{
    int temp = tree[x].add;
    if (tree[x].cor >= 0)
    {
        tree[ls].add = 0;
        tree[rs].add = 0;
        temp += tree[x].cor;
        tree[ls].cor = tree[x].cor;
        tree[rs].cor = tree[x].cor;
        tree[ls].sum = (tree[ls].r - tree[ls].l + 1) * (W - temp);
        tree[rs].sum = (tree[ls].r - tree[ls].l + 1) * (W - temp);
        // tree[ls].sum = (tree[ls].r - tree[ls].l + 1) * (temp);
		// tree[rs].sum = (tree[rs].r - tree[rs].l + 1) * (temp);
    }
    else
    {
        tree[ls].add += tree[x].add;
        tree[rs].add += tree[x].add;
		tree[ls].sum -= (tree[ls].r - tree[ls].l + 1) * (temp);
		tree[rs].sum -= (tree[rs].r - tree[rs].l + 1) * (temp);
    }
    tree[x].add = 0;
    tree[x].cor = -1;
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].cor = -1;
    if (l == r)
    {
        tree[x].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(x);
}

void upadd(int x, int l, int r, int w)
{
    if (tree[x].l >= l && tree[x].r <= r)
    {
        tree[x].add += w; 
		tree[x].sum -= (tree[x].r - tree[x].l + 1) * (tree[x].add);
		return;
    }
	int mid = (tree[x].l + tree[x].r) >> 1;
    down(x);
	if (l <= mid) upadd(ls, l, r, w);
    if (r > mid) upadd(rs, l, r, w);
    pushup(x);
}

void upcor(int x, int l, int r, int w)
{
    if (tree[x].l >= l && tree[x].r <= r)
    {
        tree[x].cor = w; 
        tree[x].add = 0;
		tree[x].sum = (tree[x].r - tree[x].l + 1) * (W - tree[x].cor);
        return;
    }
	int mid = (tree[x].l + tree[x].r) >> 1;
    down(x);
	if (l <= mid) upcor(ls, l, r, w);
	if (r > mid) upcor(rs, l, r, w);
    pushup(x);
}

int ask(int x, int l, int r)
{
    int sum = 0;
    if (tree[x].l >= l && tree[x].r <= r)
    {
        return (tree[x].sum - (res[tree[x].r] - res[tree[x].l - 1])) / W;
    }
    // if (tree[x].l == tree[x].r)
    // {
    //     if (tree[x].sum > W) return b[tree[x].r];
    //     else return 0;
    // }
    int mid = (tree[x].l + tree[x].r) >> 1;
    down(x);
    if (l <= mid) sum += ask(ls, l, r);
    if (r > mid) sum += ask(rs, l, r);
    pushup(x);
    return sum;
}

int main()
{
    scanf("%d%d%d", &n, &m, &W);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + b[i];
        res[i] = res[i - 1] + W - a[i];
    }
	build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, w;
            scanf("%d%d%d", &l, &r, &w);
            upadd(1, l, r, w);
        }
        else if (op == 2)
        {
            int l, r, w;
            scanf("%d%d%d", &l, &r, &w);
            upcor(1, l, r, w);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", ask(1, l, r));
        }
    }
    return 0;
}
