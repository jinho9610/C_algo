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

#define MOD 1000000007;
#define INVALID -1;

int n, h[10001], dp[10001][5001]; // i번째 제단까지 진행을 했을 때 높이가 j인 경우의 수

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    //양쪽 끝 비교, 0이 아니면 경우의 수 0
    if (h[1] != 0 || h[n] != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    // 가장 높은 높이 비교, 실패
    memset(dp, 0x00, sizeof(dp));

    dp[1][0] = 1;
    // i 번째 재단에서 가능한 높이 경우의 수를 넣는다
    for (int i = 1; i < n; i++)
    {
        if (h[i] != -1) // 도둑 맞지 않은 경우
        {
            int j = h[i];
            if (j - 1 >= 0)
                dp[i][j] += dp[i - 1][j - 1], dp[i][j] %= MOD;

            dp[i][j] += dp[i - 1][j], dp[i][j] %= MOD;

            if (j + 1 <= 5000)
                dp[i][j] += dp[i - 1][j + 1], dp[i][j] %= MOD;
        }
        for (int j = 0; j <= n / 2; j++)
        {
            // i 번째 재단이 j이 높이를 갖는 경우의 수
            //j-->이전의 높이가 j+1, j, j-1 합쳐지는 경우의 수
            dp[i][j] += dp[i - 1][j - 1], dp[i][j] %= MOD;
            dp[i][j] += dp[i - 1][j], dp[i][j] %= MOD;
            dp[i][j] += dp[i - 1][j + 1], dp[i][j] %= MOD;
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}