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
    const int INF = 1e9;
    vector<int> lis;
    lis.push_back(-INF);

    for (int i = 1; i <= n; i++)
    {
        if (lis.back() < arr[i])
            lis.push_back(arr[i]), ans++;
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }

    cout << ans << endl;

    return 0;
}