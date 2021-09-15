/* BOJ 1633 최고의 팀 만들기 */
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

#define endl '\n'

typedef long long ll;

int w[1001], b[1001], n = 1;
int dp[1002][16][16];

int knapsack(int idx, int w_cnt, int b_cnt)
{
    if (idx > n)
        return 0;

    int &ret = dp[idx][w_cnt][b_cnt];

    if (ret != -1)
        return ret;

    if (w_cnt > 0)
        ret = max(ret, knapsack(idx + 1, w_cnt - 1, b_cnt) + w[idx]);

    if (b_cnt > 0)
        ret = max(ret, knapsack(idx + 1, w_cnt, b_cnt - 1) + b[idx]);

    ret = max(ret, knapsack(idx + 1, w_cnt, b_cnt));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    while (cin >> w[n] >> b[n])
    {
        n++;
    }
    n--;

    memset(dp, 0xff, sizeof(dp));

    cout << knapsack(0, 15, 15) << endl;

    return 0;
}