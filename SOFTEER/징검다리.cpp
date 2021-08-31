#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define endl '\n'

typedef long long ll;

int n, arr[3001], dp[3001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);

        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}