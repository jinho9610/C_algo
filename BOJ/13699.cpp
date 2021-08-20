/* BOJ 13699 점화식 */
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
ll dp[36];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n;

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= i; k++)
            dp[i] += dp[k - 1] * dp[i - k];

    cout << dp[n] << endl;

    return 0;
}