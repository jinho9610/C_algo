/* BOJ 9095 123 더하기 */
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

int T, dp[13];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i <= 11; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}