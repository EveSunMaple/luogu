#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        bool flag = true;
        for (int i = 0; i < n - 2; i += 2)
        {
            if (arr[i] != arr[i + 2])
            {
                flag = false;
                break;
            }
        }
        if (flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}