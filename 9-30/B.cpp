#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int>> arr(k);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int m;
        scanf("%d", &m);
        arr[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            cnt[arr[i][j]]++;
        }
    }
    vector<int> ans(k, 0);
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            pq.push({cnt[i], i});
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (cnt[arr[i][j]] > 1 || (cnt[arr[i][j]] == 1 && ans[i] == 0))
            {
                ans[i] = arr[i][j];
                cnt[arr[i][j]]--;
            }
        }
        if (ans[i] == 0 && !pq.empty())
        {
            ans[i] = pq.top().second;
            pq.pop();
        }
    }
    if (pq.empty())
    {
        printf("no\n");
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
