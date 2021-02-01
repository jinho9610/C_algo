// 풀이에 사용된 알고리즘:

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;

int n, dp[1500001];
pair<int, int> info[1500001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        info[i] = {a, b};
    }

    int max_val = 0;
    for (int i = n; i >= 1; i--)
    {
        if (i + info[i].first <= n + 1)
        {
            dp[i] = max(dp[i + info[i].first] + info[i].second, max_val);
            max_val = max(max_val, dp[i]);
        }
        else
            dp[i] = max_val;
    }

    cout << max_val << '\n';

    return 0;
}