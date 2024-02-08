#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

// 计算满足条件的矩形数量
int calc(int w, int h, int n, const vector<pair<int, int>> &points)
{
    vector<int> cnt(w + 1);
    for (int i = 0; i < n; i++)
    {
        cnt[points[i].first]++;
    }
    vector<int> left(w + 1), right(w + 1);
    for (int i = 1; i <= w; i++)
    {
        left[i] = left[i - 1];
        right[w - i + 1] = right[w - i + 2];
        if (cnt[i] > 0)
        {
            left[i]++;
            right[w - i + 1]++;
        }
    }
    int result = 0;
    for (int x1 = 0; x1 <= w; x1++)
    {
        for (int y1 = 0; y1 <= h; y1++)
        {
            for (int x2 = x1; x2 <= w; x2++)
            {
                int cnt_left = left[x1];
                int cnt_right = right[x2];
                int cnt_top = 0, cnt_bottom = 0;
                for (int i = 0; i < n; i++)
                {
                    int x = points[i].first;
                    int y = points[i].second;
                    if (x1 <= x && x <= x2 && y1 <= y && y <= h)
                    {
                        cnt_top += (y == y1);
                        cnt_bottom += (y == h);
                    }
                }
                if (cnt_left + cnt_right + cnt_top + cnt_bottom == 0)
                {
                    result++;
                    result %= MOD;
                }
            }
        }
    }
    return result;
}

int main()
{
    int w, h, n;
    scanf("%d%d%d", &w, &h, &n);
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        points[i] = {x, y};
    }
    int result = calc(w, h, n, points);
    printf("%d\n", result);
    return 0;
}