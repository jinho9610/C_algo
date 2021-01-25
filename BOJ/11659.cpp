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

int n, m, dp[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (i == 0)
            dp[i] = a;
        else
            dp[i] = dp[i - 1] + a;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a - 1] << '\n';
    }

    return 0;
}