/* BOJ 3673 나눌 수 있는 부분 수열 */
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

int t, T, d, n;
vector<ll> mod;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (t = 1; t <= T; t++)
    {
        cin >> d >> n;
        ll sum = 0;
        mod.clear();
        mod.resize(d);

        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            sum += a;
            mod[sum % d]++;
        }

        ll ans = 0;
        for (int i = 0; i < d; i++)
        {
            if (i == 0 && mod[i])
                ans += mod[i];

            if (mod[i] >= 2)
                ans += (mod[i] * (mod[i] - 1)) / 2;
        }

        cout << ans << endl;
    }

    return 0;
}