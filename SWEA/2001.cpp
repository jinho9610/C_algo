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

int tc, n, m;
int arr[16][16], dp[16][16];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    for (int t = 1; t <= tc; t++) // testcase
    {
        memset(arr, 0x00, sizeof(arr));
        memset(dp, 0x00, sizeof(dp));
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];

        for (int i = 1; i <= n; i++)
            dp[1][i] = arr[1][i] + dp[1][i - 1];

        for (int i = 2; i <= n; i++) // (0,0)에서 (i, j)까지 누적합 dp 생성
        {
            for (int j = 1; j <= n; j++)
            {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j] + arr[i][j];
                else
                    dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }

        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= m && j >= m)
                    result = max(result, dp[i][j] - dp[i - m][j] - dp[i][j - m] + dp[i - m][j - m]);
                else if (i < m && j >= m)
                    result = max(result, dp[i][j] - dp[i][j - m]);
                else if (i >= m && j < m)
                    result = max(result, dp[i][j] - dp[i - m][j]);
                else if (i < m && j < m)
                    result = max(result, dp[i][j]);
            }
        }

        cout << '#' << t << ' ' << result << '\n';
    }

    return 0;
}