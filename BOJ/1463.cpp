/* BOJ 1463 1로만들기 */
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

int n, dp[1000001];

int foo(int x)
{
    if (dp[x] != -1)
        return dp[x];

    int a = 1e9, b = 1e9, c = 1e9;
    if (x % 3 == 0)
        a = foo(x / 3) + 1;
    if (x % 2 == 0)
        b = foo(x / 2) + 1;

    c = foo(x - 1) + 1;

    return dp[x] = min(a, min(b, c));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++)
        dp[i] = -1;
    dp[1] = 0;
    cout << foo(n) << endl;

    return 0;
}