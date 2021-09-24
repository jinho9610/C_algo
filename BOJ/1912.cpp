/* BOJ 1912 연속합 */
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

int n, arr[100001], dp[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int ans = dp[1] = arr[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}