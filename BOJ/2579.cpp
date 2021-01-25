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

int n, arr[301], dp[301]; // 계단의 수, 계단별 점수, 계단별 획득 가능 점수 최대값

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    dp[1] = arr[1], dp[2] = dp[1] + arr[2];
    for (int i = 1; i <= n; i++)
        dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];

    cout << dp[n] << '\n';

    return 0;
}