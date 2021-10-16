/* BOJ 1563 개근상 */
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

int n;
ll ans;
string s = "";
int dp[1001][5][5];

int dfs(int cnt, int late, int absent)
{
    if (late > 1)
        return 0;
    if (absent > 2)
        return 0;
    if (cnt > n)
        return 0;
    if (cnt == n)
        return 1;

    if (dp[cnt][late][absent] != -1)
        return dp[cnt][late][absent];

    int tmp = dfs(cnt + 1, late, 0) + dfs(cnt + 1, late + 1, 0) + dfs(cnt + 1, late, absent + 1);
    return dp[cnt][late][absent] = tmp % 1000000;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n;
    memset(dp, 0xff, sizeof(dp));

    cout << dfs(0, 0, 0) << endl;

    return 0;
}