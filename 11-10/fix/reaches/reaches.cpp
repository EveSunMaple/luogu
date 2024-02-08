#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long x, y, ax, ay, bx, by;
    scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &ax, &ay, &bx, &by);

    long long sx, sy, t;
    scanf("%lld %lld %lld", &sx, &sy, &t);

    vector<pair<long long, long long>> fragments;

    // 生成碎片的坐标列表
    fragments.push_back({x, y});
    while (x <= 1e15 && y <= 1e15)
    {
        x = ax * x + bx;
        y = ay * y + by;
        if (x < 0 || y < 0)
            break;
        fragments.push_back({x, y});
    }

    int n = fragments.size();
    int time = 0;
    int ans = 0;
    int i = 0;
    int j = 0;
    // 使用枚举一段的方法
    while (i < n)
    {
        time += abs(sx - fragments[j].first) + abs(sy - fragments[j].second);
        while (time > t)
        {
            time -= abs(sx - fragments[i].first) + abs(sy - fragments[i].second);
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }

    printf("%d\n", ans);

    return 0;
}