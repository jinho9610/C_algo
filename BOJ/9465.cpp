/* BOJ 9465 스티커 */
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

int t, T, n, arr[3][100001], dp[3][100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];

        dp[1][1] = arr[1][1], dp[2][1] = arr[2][1];
        dp[1][2] = dp[2][1] + arr[1][2];
        dp[2][2] = dp[1][1] + arr[2][2];
        for (int j = 3; j <= n; j++)
        {
            for (int i = 1; i <= 2; i++)
            {
                if (i == 1)
                    dp[i][j] = max(dp[1][j - 2], max(dp[2][j - 2], dp[2][j - 1])) + arr[i][j];
                else
                    dp[i][j] = max(dp[1][j - 2], max(dp[2][j - 2], dp[1][j - 1])) + arr[i][j];
            }
        }
        cout << max(dp[1][n], dp[2][n]) << endl;
    }

    return 0;
}