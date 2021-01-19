// 풀이에 사용된 알고리즘: Dp

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

int tc, n;
int dp[11][11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    for (int t = 1; t <= tc; t++) // testcase
    {
        cin >> n;
        dp[0][0] = 1;
        dp[1][0] = 1, dp[1][1] = 1;
        for (int i = 2; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        cout << "#" << t << '\n';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
                cout << dp[i][j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}