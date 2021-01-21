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

#define K 0
#define M 1
#define my 0

int tt, n, card[1001], dp[2][1001][1001];

int calc(int turn, int left, int right)
{
    if (left == right) // 카드가 한 장만 남은 경우
    {
        if (turn == K)
            return card[left]; // 근우 턴인 경우
        else
            return 0;
    }

    if (dp[turn][left][right] != -1)
        return dp[turn][left][right];

    if (turn == K) // 현재 근우 턴인 경우
        return dp[turn][left][right] = max(calc(M, left, right - 1) + card[right], calc(M, left + 1, right) + card[left]);
    else                                                                                        // 현재 민우 턴인 경우
        return dp[turn][left][right] = min(calc(K, left, right - 1), calc(K, left + 1, right)); // 민우턴에서 정해지는 근우의 점수는, 민우가 최선을 다할 것이기 때문에 최소로 정해짐
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tt;

    for (int t = 1; t <= tt; t++)
    {
        memset(dp, -1, sizeof(dp));

        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> card[i];

        cout << calc(K, 1, n) << '\n';
    }

    return 0;
}