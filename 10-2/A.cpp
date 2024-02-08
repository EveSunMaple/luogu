#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

using namespace std;

int ans[1000001];
int tot = 0;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s; // 将字符串复制一份接在后面
    stack<int> st;
    for (int i = 0; i < n * 4; i++)
    {
        if (s[i] == '1')
        {
            st.push(i);
        }
        else
        {
            if (!st.empty()) st.pop();
            if (st.empty()) 
            {
                if (i >= n) break;
                int temp = (i + 1) % (n * 2);
                if (temp == 0) temp = n * 2;
                ans[++tot] = temp;
            }
        }
    }
    for (int i = 1; i <= tot; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
