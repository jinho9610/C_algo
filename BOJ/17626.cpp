/* BOJ 17626 Four Squares */
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

#define endl '\n'

typedef long long ll;

int n, dp[50010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; i++)
        dp[i] = 1e9;

    int x = 1;
    while (x * x < 50000)
        dp[x * x] = 1, x++;

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 1)
            continue;
        else
            for (int k = 1; k <= i / 2; k++)
                dp[i] = min(dp[i], dp[k] + dp[i - k]);
    }

    cout << dp[n] << endl;

    return 0;
}