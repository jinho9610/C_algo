/* BOJ 9655 돌 게임 */
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
bool dp[1010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n;

    dp[1] = dp[3] = true;
    for (int i = 4; i <= n; i++)
        dp[i] = !dp[i - 1] || !dp[i - 3];

    if (dp[n])
        cout << "SK" << endl;
    else
        cout << "CY" << endl;
    cout << endl;

    return 0;
}