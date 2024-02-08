#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> color(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &color[i]);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    int count = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (color[u] == 1)
        {
            count++;
            color[u] = 0;
        }

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 1)
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        printf("%d\n", count);
    }
    else
    {
        printf("impossible\n");
    }

    return 0;
}