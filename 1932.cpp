// 풀이에 사용된 알고리즘 : dp

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

int n;
int dp[501][501];
int arr[501][501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
            if (i == 0)
            {
                if (j == 0)
                    dp[i][j] = arr[i][j];
            }
            else
            {
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + arr[i][j];
                }
                else if (j == i)
                {
                    dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, dp[n - 1][i]);

    cout << result << '\n';

    return 0;
}