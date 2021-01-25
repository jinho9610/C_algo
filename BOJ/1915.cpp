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

int n, m, square[1001][1001], dp[1001][1001], result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) // 배열 입력 받기
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            square[i][j] = c - '0';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 0) // 첫번재 행은 신경 쓸 필요 없음
                dp[i][j] = square[i][j];

            else
            {
                if (square[i][j]) // 1인 원소에 한해서만 연산
                {
                    int mn = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    dp[i][j] = mn + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
    }

    cout << result * result << '\n';

    return 0;
}